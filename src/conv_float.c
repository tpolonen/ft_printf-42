/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:25:27 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/19 17:31:32 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
 
static double	get_rounding(int precision)
{
	double	ret;

	ret = 0.5;
	while (precision)
	{
		ret *= 0.1;
		precision--;
	}
	return (ret);
}

static int	conv_dec_notation(long double num, int negative,
		int print, t_token *token)
{
	size_t		ipart;	
	long double	fpart;
	int			wlen;
	int			ret;
	int			flen;

	ipart = (size_t)num;
	fpart = num - (long double)ipart;
	wlen = ft_sizelen(ipart, 10) + 1 + token->precision;
	if (!print)
		return (wlen);
	ret = 0;
	if (token->width > 0)
		ret += putset(token->width - (wlen + negative), token->pchar);
	fpart *= ft_powl(10, token->precision);
	ret += write(1, "-", negative);
	ret += putnum(ipart, 10, 0, 0);
	if (token->precision)
	{
		char c;
		ret += write(1, ".", 1);
		fpart += get_rounding(token->precision);
		while (token->precision--)
		{
			c = '0' + (char)fpart;
			ret += write(1, &c, 1);
			fpart -= (c - '0');
			fpart *= 10.0;
		}
	}
	return (ret);
}

/*  1. Your exponent starts at zero.
    2. Slide the decimal so there is only one non-zero digit 
      to the left of the decimal.
      -  Each time you slide the decimal to the left increases the exp. by 1.
      -  Each time you slide the decimal to the right decreases the exp. by 1.
    3. Trim off any leading zeros (on the left end of the significand)
    4. Trim off any trailing zeros (on the right end of the significand)
	   only if the original number had no decimal point. 
	   We’re assuming they’re not significant unless otherwise specified.
*/
static int	conv_sci_notation(long double num, int negative,
		int print, t_token *token)
{
	size_t	exponent;
	int		ret;

	ret = 0;
	exponent = 0;
	if (num > 10.0)
	{
		while (num > 10.0)
		{
			exponent++;
			num /= 10.0;
		}
	}
	ret += conv_dec_notation(num, negative, 1, token);
	ret += write(1, "e", 1);
	if (negative)
		ret += write(1, "-", 1);
	ret += putnum(exponent, 10, 0, 0);
	return (ret);
}
static int	conv_shortest_float(long double num, int negative,
		t_token *token)
{
	return (0);
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

static int	check_exceptions(long double num, int *ret,
		int *negative, t_token *token)
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
	if ((-1.0 / num) == (-1.0 / 0.0))
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
	int			ret;
	int			negative;

	ret = 0;
	negative = 0;
	if (token->specs & LDOUBLE)
		num = va_arg(args, long double);
	else
		num = (long double)va_arg(args, double);
	if (check_exceptions(num, &ret, &negative, token))
		return (ret);
	if (num < 0.0)
	{
		negative = 1;
		num = ft_fabsl(num);
	}
	if (token->precision == -1)
		token->precision = 6;
	if (token->specs & SCI_DOUBLE)
		return (conv_sci_notation(num, negative, 1, token));
	else if (token->specs & DEC_DOUBLE)
		return (conv_dec_notation(num, negative, 1, token));
	return (conv_shortest_float(num, negative, token));
}
