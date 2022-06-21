/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:25:27 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/21 20:37:59 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* So we want to convert float of arbitrary size and precision into array of
 * printable chars. Okay. Since we are using floating point numbers,
 * we could utilize the actual floating point?
 *
 * 1. Start with the number.
 * 2. Find out which direction the period is.
 * 3. If the number is under 1.0, multiply it by ten until it's greater than 1.
 * 4. If the number is over 10.0, multiply it by 0.1 until it's less than 10.
 * 5. Now we know the exponent. Yay.
 *
 * As a side effect, this function also produces the normalized version of
 * the original number.
 */

static ssize_t	get_exponent(long double num, long double *mantissa)
{
	ssize_t	exponent;

	exponent = 0;
	*mantissa = num;
	if (num == 0.0)
		return (0);
	if (num < 1.0)
	{
		while (*mantissa < 1.0)
		{
			*mantissa *= 10.0;
			exponent--;
		}
	}
	else
	{
		while (*mantissa >= 10.0)
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
 * 3. Negative zero can be found by dividing any number with it:
 *    If it produces negative infinity, then it is negative zero.
 * 
 * There is probably a more elegant way to produce output with different
 * letter cases.
 */

static int	check_exceptions(long double num, int *ret, int *negative,
		t_token *token)
{
	*ret = 0;
	*negative = 0;
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
	if ((-1.0 / num) == (-1.0 / 0.0) || num < 0.0)
		*negative = 1;
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
	long double	mantissa;
	ssize_t		exponent;
	int			negative;
	int			ret;

	ret = 0;
	if (token->specs & LDOUBLE)
		num = va_arg(args, long double);
	else
		num = (long double)(double)va_arg(args, double);
	if (check_exceptions(num, &ret, &negative, token))
		return (ret);
	num = ft_fabsl(num);
	if (token->precision < 0)
		token->precision = 6;
	exponent = get_exponent(num, &mantissa);
	ret += (int)write(1, "-", (size_t)negative);
	if (token->specs & SCI_DOUBLE)
		ret += conv_science_notation(mantissa, exponent, 0, token);
	else if (token->specs & DEC_DOUBLE)
		ret += conv_decimal_notation(mantissa, exponent, 0, token);
	else if (token->specs & SHORTEST_F)
		ret += conv_shortest_notation(mantissa, exponent, token);
	return (ret);
}
