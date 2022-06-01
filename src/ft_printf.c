/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/01 12:32:48 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
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
	"l",
	"ll",
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
	return ;
}

static void get_length(int *token, char **seek)
{
	return ;
}

static void	get_flag(int *token, char **seek)
{
	return ;
}

static int *get_token(const char *start)
{
	int			token;
	const char	*seek;

	token = 0;
	seek = start;
	get_flag(&token, &seek);
	get_length(&token, &seek);
	get_conv(&token, &seek);
	return token;
}

int	ft_printf(const char *restrict format, ...)
{
	va_list	arg_ptr;
	int		n;
	t_dstr	*out;

	va_start(arg_ptr, format);
	n = 0;
	if (ft_dstrnew(&out, 8) == -1)
		return (-1);
	while (format[n] != '\0')
	{
		if (format[n] != '%')
			ft_dstraddc(&out, format[n]);
		else if (format[n + 1] == '%')
			ft_dstraddc(&out, format[n++]);
		else 
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
			;
		n++;
	}
	va_end(arg_ptr);
	write(1, out->str, out->len);
	return (ft_dstrclose(&out, NULL));
}
