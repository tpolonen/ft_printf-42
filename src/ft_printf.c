/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/03 14:01:33 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prototype of format tags is:
// %[flags][width][.precision][length mod]conversion

// Conversions that need to be handled per subject:
// csp
// diouxX with flags hh, h, l, ll
// f with flags l, L

// Also needs to be managed:
// %%
// flags `-+ #0`
// minimum field-width
// precision

// we probably need to have some hardcoded checks inside flag reading
// for minimum width and precision. we also have to save that info
// somewhere. fuck. i thought we could have managed to do this
// just with bitflags.

// left padding can be done while parsing but right padding and
// precision are done later. so what do? completely branch off
// function during parsing or what

// path of least resistance is probably
// - create some context struct that is allocated completely in stack
// - get token during parsing like it's done now but save it in struct
// - check for precision and field width during flags ->
// - if either is found, they have space allocated in the struct
// - instead of passing token around, pass the struct

// is field width just a number immediately after percent mark?
// if precision just a number following a period after possible field width?
// so actually we could read the field width and precision first. possibly
// inside the get_token function.
// width can be after any flag specifier ;_;
// so during flag reading for every char:
//  -check if there's a number and then read width
//  -check if there's a period and then read precision
//  -put both/either/neither in the context struct

// token struct?
// -int spec
// -int width
// -int precision

// make it a static in main and reset after each use to save in lines.

// some sources say that flags come first and width/prec after...

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
//        h,hh,l,ll,j,z,t,L < length specifiers
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

// idea is that even if we don't handle the specific flag, we have some default case
// per type so the function prints something and doesn't segfault if unimplemented
// but ISO-specified conversion is requested.

static const char	g_flags[] = "-+ #0";
static const int	g_flag_count = 5;
static const char	*g_length[] = {
	"h",
	"hh",
	"l",
	"ll",
	"j",
	"z",
	"t",
	"L"
};
static const char	g_length_count = 8;
static const char	g_conv[] = "cdieEfFgGosuxXpn%";
static const char	g_conv_count = 17;

// next three functions could probably be rolled together somehow
static void get_conv(t_token *token, char **seek)
{
	int	i;
	int	stop;

	i = 0;
	while (i < g_conv_count)
	{
		if (**seek == g_conv[g_conv_count - i - 1])
		{
			token->specs |= (1 << i);
			break ;
		}
		i++;
	}
}

static void get_length(t_token *token, char **seek)
{
	int	i;
	int	stop;

	i = 0;
	while (i < g_length_count)
	{
		if (ft_strncmp(*seek, g_length[g_length_count - i - 1], \
					ft_strlen(g_length[g_length_count - i - 1])) == 0)
		{
			token->specs |= 1 << i;
			(*seek) += ft_strlen(g_length[g_length_count - i - 1]);
			break ;
		}
		i++;
	}
	token->specs <<= g_conv_count;
}

static void	get_flag(t_token *token, char **seek)
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
				token->specs |= 1 << i;
				stop = 0;
			}
			i++;
		}
		if (stop)
			break ;
		(*seek)++;
	}
	token->specs <<= g_length_count;
}

static int get_token(t_token *token, char **start)
{
	(*start)++;
	*token = (t_token) {0, 0, 0};
	get_flag(token, start);
	//so can we get width and precision here or what
	//we can.
	get_length(token, start);
	get_conv(token, start);
	return (token->specs != 0);
}

/*
 * 1. Create a dynamic string.
 * 2. Insert characters from format sign until null byte or '%' is reached.
 * 3. Turn conversion into token, containing bitflags, width and precision.
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
	t_token			token;
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
			if (token.specs & INTEGER)
				int_handler(&out, &token, args);
			if (token.specs & CHAR)
				char_handler(&out, &token, args);
			if (token.specs & FLOAT)
				float_handler(&out, &token, args);
		}
		format++;
	}
	va_end(args);
	write(1, out->str, out->len);
	return (ft_dstrclose(&out, NULL));
}
