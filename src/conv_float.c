/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:25:27 by tpolonen          #+#    #+#             */
/*   Updated: 2022/07/19 21:30:06 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* So we want to convert float of arbitrary size and precision into array of
 * printable chars. Okay. Since we are using floating point numbers,
 * we could utilize the actual floating point?
 *
 * 1. Start with the number.
 * 2. Find out which direction the radix is.
 * 3. If the number is under 1.0, multiply it by ten until it's greater than 1.
 * 4. If the number is over 10.0, multiply it by 0.1 until it's less than 10.
 * 5. Now we know the exponent. Yay. Also we normalized the number, 
 *    which can now be found in *mantissa.
 */

static ssize_t	normalize_double(long double num, long double *mantissa)
{
	ssize_t	exponent;

	exponent = 0;
	*mantissa = num;
	if (num == 0.0)
		return (0);
	if (ft_fabsl(num) < 1.0)
	{
		while (ft_fabsl(*mantissa) < 1.0)
		{
			*mantissa *= 10.0;
			exponent--;
		}
	}
	else
	{
		while (ft_fabsl(*mantissa) >= 10.0)
		{
			*mantissa /= 10.0;
			exponent++;
		}
	}
	return (exponent);
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
			*ret = putstr("INF", token->width, ' ');
		else if (-1.0 / 0.0 == num)
			*ret = putstr("-INF", token->width, ' ');
	}
	else
	{
		if (num != num)
			*ret = putstr("nan", token->width, ' ');
		else if (1.0 / 0.0 == num)
			*ret = putstr("inf", token->width, ' ');
		else if (-1.0 / 0.0 == num)
			*ret = putstr("-inf", token->width, ' ');
	}
	return (*ret);
}

static long double	round_mantissa(long double mantissa, ssize_t exponent,
		t_token *token)
{
	if (token->specs & SCI_DOUBLE)
		return (round_ld(mantissa, token->precision + 1, 1));
	if (token->specs & DEC_DOUBLE)
	{
		if (exponent >= 0)
			return (round_ld(mantissa, exponent + 1 + token->precision, 1));
		return (round_ld(mantissa, token->precision, 1));
	}
	return (mantissa);
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
	long double	mantissa;
	ssize_t		exponent;
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
	exponent = normalize_double(num, &mantissa);
	mantissa = round_mantissa(mantissa, exponent, token);
	exponent += normalize_double(num, &mantissa);
	if (token->specs & SCI_DOUBLE)
		ret += conv_science_notation(mantissa, exponent, token);
	else if (token->specs & DEC_DOUBLE)
		ret += conv_decimal_notation(mantissa, exponent, token);
	else if (token->specs & SHORTEST_F)
		ret += conv_shortest_notation(mantissa, exponent, token);
	return (ret);
}
