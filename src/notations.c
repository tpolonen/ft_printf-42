/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:09:48 by teppo             #+#    #+#             */
/*   Updated: 2022/07/07 20:01:46 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* We use these functions after we have normalized the number and got the
 * mantissa and exponent. This information can be used to produce any of
 * these conversions.
 */

/* Each of these functions has to be in charge of printing their own prefixes:
 * counting their length is so involved process it's better for them to do it
 * individually than try to make some kind of 'one-size-fits-all' megafunction
 * with dozens of if-else-branches.
 */

/* Speaking of which: Here's the function that actually prints the prefixes
 * eq. everything that is printed before the number itself - padding to width
 * with whitespace or 0 and the requested sign (minus, plus or empty space).
 */

static int	check_prefix(t_token *token, int len, long double *mantissa)
{
	int	ret;
	int	prefix_len;
	int	prefix_printed;
	int	negative;

	ret = 0;
	negative = (*mantissa < 0.0 || 42.0 / *mantissa == -1.0 / 0.0);
	prefix_len = 0;
	prefix_printed = 0;
	if (token->precision & F_PADDED_POS || \
			token->precision & F_PRINT_PLUS || negative)
		prefix_len = 1;
	if (token->pchar == '0')
	{
		ret += print_prefix(negative, *mantissa == 0.0L, token);
		prefix_printed = 1;
	}
	if (len + prefix_len < token->width)
		ret += ft_putset(token->width - len - prefix_len, token->pchar);
	if (prefix_len > 0 && prefix_printed == 0)
		ret += print_prefix(negative, *mantissa == 0.0L, token);
	*mantissa = ft_fabsl(*mantissa);
	return (ret);
}

/* eE: Print the most significant number.
 *     Print radix.
 *     Print as many numbers as is required by precision.
 *     Fill with zeroes as usual if numbers run out before precision.
 */

int	conv_science_notation(long double mantissa, ssize_t exponent,
		t_token *token)
{
	int			ret;

	ret = check_prefix(token, 3 + (token->precision > 0 || \
				token->specs & F_ALT_FORM) + token->precision + (exponent != 0)
			* ft_max(2, (int)ft_ssizelen(exponent, 10)), &mantissa);
	ret += putfloat(1, &mantissa, 0, 0);
	if (token->precision || token->specs & F_ALT_FORM)
		ret += (int)write(1, ".", 1);
	ret += putfloat(token->precision, &mantissa, 1, 0);
	if (exponent == 0)
		return (ret);
	ret += (int)write(1, "e", 1);
	if (exponent < 0)
		ret += (int)write(1, "-", 1);
	else
		ret += (int)write(1, "+", 1);
	return (ret + ft_putnum(ft_ssabs(exponent), 10, 2, 0));
}

/* fF: Is exponent positive or negative?
 *     If positive: - Print normalized float digit by digit.
 *                  - Repeat until we hit the radix.
 *                  - If precision > 0:
 *                       Print radix and any remaining numbers up to precision.
 *     If negative: - Print 0 and radix.
 *                  - Print zeroes until exp. is zero or precision runs out.
 *                  - If any precision is left, fill with normalized float.
 */

int	conv_decimal_notation(long double mantissa, ssize_t exponent,
		t_token *token)
{
	int			ret;

	if (exponent >= 0)
	{
		ret = check_prefix(token, (int)++exponent + (token->precision > 0 || \
					token->specs & F_ALT_FORM) + token->precision, &mantissa);
		ret += putfloat(exponent, &mantissa, 0, 0);
		ret += (int)write(1, ".", (token->precision > 0 || \
					token->specs & F_ALT_FORM));
	}
	else
	{
		ret = check_prefix(token, 1 + (token->precision > 0 || \
					token->specs & F_ALT_FORM) + token->precision, &mantissa);
		ret += (int)write(1, "0", 1);
		if (token->precision > 0 || token->specs & F_ALT_FORM)
		{	
			ret += (int)write(1, ".", 1);
			if (token->precision < -exponent)
				return (ret + ft_putset(token->precision, '0'));
			ret += ft_putset(ft_abs((int)(exponent + 1)), '0');
			token->precision -= ft_abs((int)(exponent + 1));
		}
	}
	return (ret + putfloat(token->precision, &mantissa, 1, 0));
}

static int	trim_z(long double num, int precision)
{
	int	ocount;
	int	ipart;
	int	i;

	ocount = 0;
	i = 0;
	while (i < precision)
	{
		ipart = (int)num;
		num = (num - (long double) ipart) * 10.0;
		if (ipart == 0)
			ocount++;
		else
			ocount = 0;
		i++;
	}
	return (precision - ocount);
}

/* gG: If precision is zero, it is treated as 1.
 *     Precision determines how many significant digits are printed.
 *     Use eE if exponent is less than -4 or greater or equal to precision.
 *     Otherwise use fF.
 *     Trailing zeroes are removed from the fractional part of the result;
 *     a decimal point appears only if it is followed by at least one digit.
 *
 *     ...look, honestly this conversion has been reverse engineered by
 *     pure brute force and endless frustration. It produces similar results
 *     to actual printf-conversion, probably by pure coincidence.
 *     I would heartily recommend looking elsewhere if you want to
 *     replicate this conversion in your own version of printf.
 */

int	conv_shortest_notation(long double mantissa, ssize_t exponent,
		t_token *token)
{
	int	scilen;
	int	declen;

	if (token->precision == 0)
		token->precision = 1;
	token->precision--;
	token->precision = trim_z(mantissa, token->precision);
	scilen = 3 + (token->precision > 0) + token->precision + \
		ft_max(2, (int)ft_ssizelen(exponent, 10));
	if (exponent > 0)
		declen = (int)exponent + 1 + (token->precision > 0) + \
			token->precision;
	else
		declen = 1 + (token->precision > 0) + token->precision;
	if (scilen < declen)
		return (conv_science_notation(mantissa, exponent, token));
	if (exponent < 0)
		token->precision++;
	return (conv_decimal_notation(mantissa, exponent, token));
}
