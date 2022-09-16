/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:25:27 by tpolonen          #+#    #+#             */
/*   Updated: 2022/09/16 17:20:43 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_inf(const char *str, int *ret, t_token *token)
{
	char	buf[5];
	int		i;

	if ((token->specs & F_PADDED_POS) || (token->specs & F_PRINT_PLUS))
	{
		buf[0] = ' ';
		if (token->specs & F_PRINT_PLUS)
			buf[0] = '+';
		i = -1;
		while (++i < 4)
			buf[i + 1] = str[i];
		*ret = putstr(buf, token->width, ' ');
	}
	else
		*ret = putstr(str, token->width, ' ');
	return (*ret);
}

/* Basic principles for checking float exceptions are:
 * 1. NaN == NaN is always false.
 * 2. Dividing by zero will always produce infinity:
 *    Sign depends on which number was divided.
 *
 * There is probably a more elegant way to produce output with different
 * letter cases.
 */

static int	check_exceptions(long double num, int *ret,	t_token *token)
{
	*ret = 0;
	if (token->specs & ALL_CAPS)
	{
		if (num != num)
			*ret = putstr("NAN", token->width, ' ');
		else if (1.0 / 0.0 == num)
			*ret = print_inf("INF", ret, token);
		else if (-1.0 / 0.0 == num)
			*ret = putstr("-INF", token->width, ' ');
	}
	else
	{
		if (num != num)
			*ret = putstr("nan", token->width, ' ');
		else if (1.0 / 0.0 == num)
			*ret = print_inf("inf", ret, token);
		else if (-1.0 / 0.0 == num)
			*ret = putstr("-inf", token->width, ' ');
	}
	return (*ret);
}

/* 1. To start with, we convert all floats to long doubles so they can be
 *    handled with same functions.
 * 2. Check for exceptions - if any are found, print the relevant message
 *    and return.
 * 3. If precision was not set, it is 6 by default.
 *
 * After this preliminary setup, we can convert the float in the format
 * that was specified.
 */

int	conv_float(t_token *token, va_list args)
{
	long double	num;
	int			ret;

	ret = 0;
	if (token->specs & LDOUBLE)
		num = va_arg(args, long double);
	else
		num = (long double)(double)va_arg(args, double);
	if (check_exceptions(num, &ret, token))
		return (ret);
	if (token->precision < 0)
		token->precision = 6;
	if (token->specs & SCI_DOUBLE)
		ret += conv_science_notation(num, token);
	else if (token->specs & DEC_DOUBLE)
		ret += conv_decimal_notation(num, token);
	else if (token->specs & SHORTEST_F)
		ret += conv_shortest_notation(num, token);
	return (ret);
}
