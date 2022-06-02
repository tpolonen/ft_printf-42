/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/02 17:38:38 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prototype of format tags is:
// %[flags][width][.precision][length mod]conversion

// Conversions that need to be handled per subject:
// csp
// diouxX with flags hh, h, l, ll
// f with flags l, L

// so types we actually need to handle are
// diouxX - integer as either signed/unsigned decimal, unsigned octal or unsigned hex
// c - first byte of argument is printed, so char
// s - string, so char pointer until null byte is reached
// p - is pointer address if I remember correctly, so also integer? in hex
// f - float, infinity and NaN are printed as "inf" and "nan" respectively

// so types are
// - integer
// - short
// - long
// - long long
// - char (pointer)
// - float

// not too bad to handle with if/else checks IF we handle integer types with in one branch.
// we only need to get flag and type passed to function that handles the actual conversion
// so we have functions
// * handle_int(va_list, token, &out)
//  - branches off to handle_char, handle short, handle_long, handle_long_long
//  - or alternatively convert the input always to long long...
//  - we probably need to branch off to different outputs eventually anyways,
//    order of operations matters.
// * handle_char(va_list, token, &out)
//  - two cases: print char or print string, probably can be handled in this function
// * handle_float(va_list, token, &out)
//  - small f = print infinity and nan as `inf`, `nan`
//  - big F = print infinity and nan as `INF`, `NAN`

// we probably can't pass va_arg directly, but instead pass the list (pointer?) and
// let the handle function handle the va_arg.

// probably special case for %%, no need to go through the whole rigamarole...
// we already have a special case for %%, no need to make it any more complicated.
// actually have to, b/c linecount of main function :P
// percent is now a char type

// Also needs to be managed:
// %%
// flags `-+ #0`
// minimum field-width
// precision

// Bonuses:
// conversions e and g with L flag
// detailed flags management: `*$'`
// non existing flags:
// - %b to print in binary
// - %r to print string of non-printables
// - %k to print a date in any ordinary ISO format
// - etc...
// Alter colors, fd, other fun stuff

// token bitfield key
// 00
// not used
//   11111
//   -+ #0 < flags
//        11111111
//        h,hhh,l,ll,j,z,t,L < length specifiers
//                11111111111111111
//                cdieEfFgGosuxXpn% < conversion specifiers
// so the bitmasks for different types are
// 00000000000000001100000010111100 < integer types, specifically
// 00000000000000001100000000000000  < signed decimal
// 00000000000000000000000000100000  < unsigned decimal
// 00000000000000000000000010000000  < unsigned octal
// 00000000000000000000000000011100  < unsigned hexadecimal
// 00000000000000000000000000000100  < void * in hexadecimal
// 00000001000000000000000000000000  < signed or unsigned short
// 00000000100000000000000000000000  < signed or unsigned char
// 00000000010000000000000000000000  < signed or unsigned long
// 00000000001000000000000000000000  < signed or unsigned long long
// 00000000000100000000000000000000  < signed or unsigned intmax_t
// 00000000000010000000000000000000  < signed or unsigned size_t
// 00000000000001000000000000000000  < ptrdiff_t
// 00000000000000010000000001000000 < char types, specifically
// 00000000000000010000000000000000  < int converted to an unsigned char
// 00000000000000000000000001000000  < const char * pointing to char[]
// 00000000000000000000000000000001  < just a percent mark
// 00000000000000000011111100000000 < float types, specifically
// 00000000000000100000000000000000  < long double
// 00000000000000000011000000000000  < double rounded and converted to d.ddde+dd
// 00000000000000000000110000000000  < double rounded and converted to ddd.ddd
// 00000000000000000000001100000000  < double, shortest of the previous ones
                                    
// 00000000000001001100000000000000  < signed
// 00000000000000010000000010111100  < unsigned
// 00000000000000001100000000100000  < decimal
// 00000000000000000000000010000000  < octal
// 00000000000000000000000000011100  < hexal

// we probably make defines from these

// idea is that even if we don't handle the specific flag, we have some default case
// per type so the function prints something and doesn't segfault if unimplemented
// but ISO-specified conversion is requested.

const char	g_flags[] = "-+ #0";
const int	g_flag_count = 5;
const char	*g_length[] = {
	"h",
	"hh",
	"l",
	"ll",
	"j",
	"z",
	"t",
	"L"
};
const char	g_length_count = 8;
const char	g_conv[] = "cdieEfFgGosuxXpn%";
const char	g_conv_count = 17;

// next three functions could probably be rolled together somehow
static void get_conv(int *token, char **seek)
{
	int	i;
	int	stop;

	i = 0;
	while (i < g_conv_count)
	{
		if (**seek == g_conv[g_conv_count - i - 1])
		{
			*token |= (1 << i);
			break ;
		}
		i++;
	}
}

static void get_length(int *token, char **seek)
{
	int	i;
	int	stop;

	i = 0;
	while (i < g_length_count)
	{
		if (ft_strncmp(*seek, g_length[g_length_count - i - 1], \
					ft_strlen(g_length[g_length_count - i - 1])) == 0)
		{
			*token |= 1 << i;
			(*seek) += ft_strlen(g_length[g_length_count - i - 1]);
			break ;
		}
		i++;
	}
	*token <<= g_conv_count;
}

static void	get_flag(int *token, char **seek)
{
	int	i;
	int	stop;

	while (**seek != '\0')
	{	
		i = 0;
		stop = 1;
		while (i < g_flag_count)
		{
			if (**seek == g_flags[g_flag_count - i - 1])
			{
				*token |= 1 << i;
				stop = 0;
			}
			i++;
		}
		if (stop)
			break ;
		(*seek)++;
	}
	*token <<= g_length_count;
}

static int get_token(int *token, char **start)
{
	(*start)++;
	*token = 0;
	get_flag(token, start);
	get_length(token, start);
	get_conv(token, start);
	//if some fail condition return 0
	return (1);
}

/*
 * 1. Create a dynamic string.
 * 2. Insert characters from format sign until null byte or '%' is reached.
 * 3. Turn conversion into bitfield.
 *    ...if that fails, conversion is invalid. Just insert the next char.
 * 4. Using token and appropriate bitmask, transfer to type specific function:
 *    - pointer to dynamic string
 *    - token
 *    - and list of args
 * 5. Arg is converted into correct output and appended to dynamic string.
 * 6. Repeat until null byte is reached.
 * 7. Write contents of dynamic string directly to stdout.
 * 8. Free dynamic string and return it's length.
 */
int	ft_printf(const char *restrict format, ...)
{
	va_list			args;
	int				token;
	static t_dstr	*out;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
			ft_dstraddc(&out, *format);
		else if (!get_token(&token, (char **) &format))
			ft_dstraddc(&out, *format);
		else
		{
			if (token & INTEGER)
				int_handler(&out, token, args);
			if (token & CHAR)
				char_handler(&out, token, args);
			if (token & FLOAT)
				float_handler(&out, token, args);
		}
		format++;
	}
	va_end(args);
	write(1, out->str, out->len);
	return (ft_dstrclose(&out, NULL));
}
