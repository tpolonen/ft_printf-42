/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/31 20:08:24 by tpolonen         ###   ########.fr       */
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
//	va_list	arg;
	int		n;
	t_dstr	*out;

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
			//convert(get_token(format + n), out, arg);
			//do we need to squeeze out the next arg here?
			//how's that gonna work?
			;
		n++;
	}
	write(1, out->str, out->len);
	return (ft_dstrclose(&out, NULL));
}
