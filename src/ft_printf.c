/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/01 17:48:29 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
// - char (pointer)
// - float

// not too bad to handle with if/else checks. we only need to get flag and type
// passed to function that handles the actual conversion
// so we have functions
// * handle_int(va_arg, flags, seek)
//  - branches off to handle_char, handle short, handle_long, handle_long_long
//  - or alternatively convert the input always to long long...
//  - we probably need to branch off to different outputs eventually anyways,
//    order of operations matters.
// * handle_char_ptr(va_arg, flags, seek)
//  - two cases: print char or print string, probably can be handled in this function
// * handle_float(va_arg, flags, seek)
//  - small f = print infinity and nan as `inf`, `nan`
//  - big F = print infinity and nan as `INF`, `NAN`

// probably special case for %%, no need to go through the whole rigamarole...
// we already have a special case for %%, no need to make it any more complicated.

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

const char	g_flags[] = "-+ #0";
const int	g_flag_count = 5;

const char	*g_length[] = {
	"hh",
	"h",
	"ll",
	"l",
	"j",
	"z",
	"t",
	"L"
};
const char	g_length_count = 8;

const char	g_conv[] = "cdieEfgGosuxXpn%";
const char	g_conv_count = 15;

static void get_conv(int *token, char **seek)
{
	int	i;
	int	stop;

	i = 0;
	while (i < g_conv_count)
	{
		if (**seek == g_conv[i])
		{
			printf("found conv! %c == %c\nwe should flip bit %d\n", **seek, g_conv[i], i);
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
		if (ft_strncmp(*seek, g_length[i], ft_strlen(g_length[i])) == 0)
		{
			printf("found length! %c == %s\nwe should flip bit %d\n", **seek, g_length[i], i);
			*token |= 1 << i;
			(*seek) += ft_strlen(g_length[i]);
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
			if (**seek == g_flags[i])
			{
				printf("found flag! %c == %c\nwe should flip bit %d\n", **seek, g_flags[i], i);
				*token |= 1 << i;
				stop = 0;
			}
			i++;
		}
		if (stop)
			break ;
		(*seek)++;
		printf("moving to check if %c is flag\n", **seek);
	}
	*token <<= g_length_count;
}

static int get_token(int *token, char **start)
{
	printf("we get token\n");
	(*start)++;
	*token = 0;
	get_flag(token, start);
	get_length(token, start);
	get_conv(token, start);
	//if some fail condition return 0
	return (1);
}

//good ol' bitprint from stackoverflow
//should probably copy one we made for fillit and put that in libft
// Assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

__attribute__ ((format (printf, 1, 2)))
int	ft_printf(const char *restrict format, ...)
{
	va_list	arg_ptr;
	int		token;
	t_dstr	*out;


	va_start(arg_ptr, format);
	if (ft_dstrnew(&out, 8) == -1)
		return (-1);
	while (*format != '\0')
	{
		if (*format != '%')
			ft_dstraddc(&out, *format);
		else if (*(format + 1) == '%')
			ft_dstraddc(&out, *format++);
		else if (!get_token(&token, (char **) &format))
			ft_dstraddc(&out, *format); //we should send a compiler error or something here
		else
		{
			printBits(sizeof(int), &token);
		}

			//get token as bits in int
			//feed token, dstr and corresponding item in va_args (arg itself?) to dispatcher
			//so something like
			//convert(get_token(format + n), &out, arg);
			//do we need to squeeze out the next arg here?
			//how's that gonna work?
			//after getting full token we know which type the next conversion will be
			//can we get the next token by size in bytes or do we have to provide type?
			//I'm thinking of storing types/bitecounts in array where index corresponds
			//to specific conversion flag, so it would be possible to provide size of
			//arg after token has been processed
			//do we need to iterate through the string first to get token count so we know
			//the size of va_list? linked list would make sense here, since we need to
			//insert processed tokens between plaintext strings
			//looks like va_arg(dest, type) is kind of iterator. so no need to count
			//what va_arg returns if there's not enough args for tokens?
			//random errors. how can we handle that situation without counting tokens
			//first and comparing them to args. we can't check for next arg without
			//calling va_arg.
			//can we actually expect that va_arg returns -1 after it's emptied?
			//probably worth testing in cluster & with ft_printf testers.
			//IF __attribute__ is actually allowed, that solves issue with not matching
			//conv/arg numbers...
			//should we put the type funnel here in main? would be more readable I guess
			//if linecount permits. we could make bitmasks for each type and check if
			//token matches a type with bitwise &
			;
		format++;
	}
	va_end(arg_ptr);
	write(1, out->str, out->len);
	return (ft_dstrclose(&out, NULL));
}
