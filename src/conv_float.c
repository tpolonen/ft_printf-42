/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:25:27 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/20 11:27:26 by teppo            ###   ########.fr       */
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
/*
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
*/
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
/*
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
*/
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

/* So we want to convert float of arbitrary size and precision into array of
 * printable chars. Okay. Since we are using floating point numbers,
 * we could utilize the actual floating point?
 *
 * 1. Start with the number.
 * 2. Find out which direction the period is.
 * 3. If the number is under 1.0, multiply it by ten until it's greater than 1.
 * 4. If the number is over 10.0, multiply it by 0.1 until it's less than 10.
 * 5. Now we know the exponent. Yay.
 * 6. With this knowledge, depending on which kind of output was specified:
 *    fF: Is exponent positive or negative?
 *        If positive: - Print num converted to integer.
 *                     - Decrease integer from remainder.
 *                     - Multiply remainder by ten
 *                     - Repeat until we hit the radix.
 *                     - Print radix and any remaining numbers up to precision.
 *                       If numbers run out before precision, fill with zeroes.
 *                     - On the last number: round it somehow somewhere.
 *        If negative: - Print 0 and radix.
 *                     - Print zeroes until exponent is zero.
 *                     - Continue printing numbers as above.
 *                       If numbers run out before precision, print more zero.
 *                     - On the last number: round it somehow somewhere.
 *    eE: Print most significant number.
 *        Print radix.
 *        Print as many numbers as is required by precision.
 *        Fill with zeroes as usual if numbers run out before precision.
 *        Round off the last number as usual.
 *    gG: If precision is zero, it is treated as 1.
 *        Use eE if exponent is less than -4 or greater or equal to precision.
 *        Otherwise use fF.
 *        Trailing zeroes are removed from the fractional part of the result;
 *        a decimal point appears only if it is followed by at least one digit.
 */

static int	conv_science_notation(long double mantissa, ssize_t exponent,
		t_token *token)
{
	int			ipart;
	long double	fpart;
	int			ret;

	ret = 0;
	ipart = (int) mantissa;
	fpart = mantissa - (long double) ipart;
	ret += ft_putchar('0' + ipart);
	ret += write(1, ".", 1);
	mantissa -= (long double) ipart;
	mantissa *= 10.0;
	while (token->precision)
	{
		ipart = (int) mantissa;
		fpart = mantissa - (long double) ipart;
		ret += ft_putchar('0' + ipart);
		token->precision--;
		mantissa -= (long double) ipart;
		mantissa *= 10.0;
	}
	ret += write(1, "e", 1);
	ret += write(1, "-", exponent < 0);
	return (ret + putnum(ft_ssabs(exponent), 10, 0, 0));
}


static int	conv_decimal_notation(long double mantissa, ssize_t exponent,
		t_token *token)
{
	int			ipart;
	long double	fpart;
	int			ret;

	ret = 0;
	if (exponent >= 0)
	{
		while (exponent >= 0)
		{
			ipart = (int) mantissa;
			fpart = mantissa - (long double) ipart;
			ret += ft_putchar('0' + ipart);
			mantissa -= (long double) ipart;
			mantissa *= 10.0;
			exponent--;
		}
		if (token->precision > 0)
		{
			ret += write(1, ".", 1);
			while (token->precision > 0)
			{
				ipart = (int) mantissa;
				fpart = mantissa - (long double) ipart;
				ret += ft_putchar('0' + ipart);
				mantissa -= (long double) ipart;
				mantissa *= 10.0;
				token->precision--;
			}
		}
	}
	else
	{
		ret += write(1, "0", 1);
		if (token->precision > 0)
		{
			ret += write(1, ".", 1);
			if (token->precision < exponent)
				return (ret + putset(token->precision, '0'));
			ret += putset(exponent, '0');
			token->precision -= exponent;
			while (token->precision > 0)
			{
				ipart = (int) mantissa;
				fpart = mantissa - (long double) ipart;
				ret += ft_putchar('0' + ipart);
				mantissa -= (long double) ipart;
				mantissa *= 10.0;
				token->precision--;
			}
		}
	}
	return (ret);
}

static ssize_t	get_exponent(long double num, long double *mantissa)
{
	ssize_t	exponent;

	exponent = 0;
	*mantissa = num;
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

static int	check_exceptions(long double num, int *ret, int *negative,
		t_token *token)
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
	long double	mantissa;
	ssize_t		exponent;
	int			negative;
	int			ret;

	ret = 0;
	negative = 0;
	if (token->specs & LDOUBLE)
		num = va_arg(args, long double);
	else
		num = (long double)(double)va_arg(args, double);
	if (check_exceptions(num, &ret, &negative, token))
		return (ret);
	if (num < 0.0)
	{
		negative = 1;
		num = ft_fabsl(num);
	}
	if (token->precision < 0)
		token->precision = 6;
	exponent = get_exponent(num, &mantissa);
	if (token->specs & SCI_DOUBLE)
		return (conv_science_notation(mantissa, exponent, token));
	else if (token->specs & DEC_DOUBLE)
		return (conv_decimal_notation(mantissa, exponent, token));
	return (0);
}
