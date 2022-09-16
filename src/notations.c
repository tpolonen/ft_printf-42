/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:09:48 by teppo             #+#    #+#             */
/*   Updated: 2022/09/16 17:36:22 by teppo            ###   ########.fr       */
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

static int	check_prefix(t_token *token, int len, long double *num)
{
	int	ret;
	int	prefix_len;
	int	prefix_printed;
	int	negative;

	ret = 0;
	negative = ((*num < 0.0) || (42.0 / *num == 43.0 / -0.0));
	prefix_len = 0;
	prefix_printed = 0;
	if (token->specs & F_PADDED_POS || token->specs & F_PRINT_PLUS || negative)
		prefix_len = 1;
	if (token->pchar == '0')
	{
		ret += print_prefix(negative, *num == 0.0L, token);
		prefix_printed = 1;
	}
	if (len + prefix_len < token->width)
		ret += ft_putset(token->width - len - prefix_len, token->pchar);
	if (prefix_len > 0 && prefix_printed == 0)
		ret += print_prefix(negative, *num == 0.0L, token);
	*num = ft_fabsl(*num);
	return (ret);
}

/* eE: Print the most significant number.
 *     Print radix.
 *     Print as many numbers as is required by precision.
 *     Fill with zeroes as usual if numbers run out before precision.
 */

int	conv_science_notation(long double num, t_token *token)
{
	int			ret;
	ssize_t		exponent;
	long double	mantissa;

	exponent = normalize_double(num, &mantissa);
	ret = check_prefix(token, 3 + (token->precision > 0 || \
				token->specs & F_ALT_FORM) + token->precision + (exponent != 0)
			* ft_max(2, (int)ft_ssizelen(exponent, 10)), &mantissa);
	ret += putfl(mantissa, token, 0);
	if (exponent == 0)
		return (ret);
	ret += (int)write(1, "e", 1);
	if (exponent < 0)
		ret += (int)write(1, "-", 1);
	else
		ret += (int)write(1, "+", 1);
	return (ret + ft_putnum(ft_ssabs(exponent), 10, 2, 0));
}

/*  fF: The default case, hopefully most readable.
 */

int	conv_decimal_notation(long double num, t_token *token)
{
	int			ret;
	ssize_t		exponent;
	long double	mantissa;

	exponent = normalize_double(num, &mantissa);
	ret = check_prefix(token, (ft_max(1, (int)++exponent)) + \
			(token->precision > 0 || token->specs & F_ALT_FORM) \
			+ token->precision, &num);
	ret += putfl(num, token, 0);
	return (ret);
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

int	conv_shortest_notation(long double num, t_token *token)
{
	int			scilen;
	int			declen;
	long double	mantissa;
	ssize_t		exponent;
	int			ret;

	if (token->precision == 0)
		token->precision = 1;
	token->precision--;
	exponent = normalize_double(num, &mantissa);
	scilen = 3 + (token->precision > 0) + token->precision + \
		ft_max(2, (int)ft_ssizelen(exponent, 10));
	if (exponent > 0)
		declen = (int)exponent + 1 + (token->precision > 0) + \
			token->precision;
	else
		declen = 1 + (token->precision > 0) + token->precision;
	if (scilen < declen)
		return (conv_science_notation(num, token));
	if (exponent < 0)
		token->precision++;
	ret = check_prefix(token, (ft_max(1, (int)++exponent)) + \
			(token->precision > 0 || token->specs & F_ALT_FORM) \
			+ token->precision, &num);
	return (ret + putfl(num, token, 1));
}
