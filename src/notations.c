/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:09:48 by teppo             #+#    #+#             */
/*   Updated: 2022/06/20 22:28:52 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* We use these functions after we have normalized the number and got the
 * mantissa and exponent. This information can be used to produce any of
 * these conversions.
 */

/* eE: Print the most significant number.
 *     Print radix.
 *     Print as many numbers as is required by precision.
 *     Fill with zeroes as usual if numbers run out before precision.
 */

int	conv_science_notation(long double mantissa, ssize_t exponent,
		int trim, t_token *token)
{
	int			ret;

	ret = putfloat(1, &mantissa, 0, 0);
	if (token->precision)
		ret += write(1, ".", 1);
	ret += putfloat(token->precision, &mantissa, 1, trim);
	ret += write(1, "e", 1);
	if (exponent < 0)
		ret += write(1, "-", 1);
	else
		ret += write(1, "+", 1);
	return (ret + putnum(ft_ssabs(exponent), 10, 2, 0));
}

/* fF: Is exponent positive or negative?
 *     If positive: - Print num converted to integer.
 *                  - Decrease integer from remainder.
 *                  - Multiply remainder by ten.
 *                  - Repeat until we hit the radix.
 *                  - Print radix and any remaining numbers up to precision.
 *     If negative: - Print 0 and radix.
 *                  - Print zeroes until exponent is zero.
 *                  - Continue printing numbers as above.
 */

int	conv_decimal_notation(long double mantissa, ssize_t exponent,
		int trim, t_token *token)
{
	int			ret;

	ret = 0;
	if (exponent >= 0)
	{
		ret += putfloat(exponent + 1, &mantissa, 0, 0);
		if (token->precision > 0 && !(trim && mantissa == 0.0))
			ret += write(1, ".", 1);
	}
	else
	{
		ret += write(1, "0", 1);
		if (token->precision > 0 && !(trim && mantissa == 0.0))
		{
			ret += write(1, ".", 1);
			if (token->precision < exponent)
				return (ret + putset(token->precision, '0'));
			ret += putset(exponent, '0');
			token->precision -= exponent;
		}
	}
	ret += putfloat(token->precision, &mantissa, 1, trim);
	return (ret);
}

/* gG: If precision is zero, it is treated as 1.
 *     Use eE if exponent is less than -4 or greater or equal to precision.
 *     Otherwise use fF.
 *     Trailing zeroes are removed from the fractional part of the result;
 *     a decimal point appears only if it is followed by at least one digit.
 */

int	conv_shortest_notation(long double mantissa, ssize_t exponent,
		t_token *token)
{
	int	ret;

	ret = 0;
	if (token->precision == 0)
		token->precision = 1;
	token->precision--;
	if (exponent < -4 || exponent >= token->precision)
		ret += conv_science_notation(mantissa, exponent, 1, token);
	else
		ret += conv_decimal_notation(mantissa, exponent, 1, token);
	return (ret);
}
