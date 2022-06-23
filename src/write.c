/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:18:12 by teppo             #+#    #+#             */
/*   Updated: 2022/06/23 14:00:04 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This is pretty kludgy attempt at saving lines from other num conversion
 * functions. Probably could be refactored in existing functions somehow.
 * ._.
 */

int	print_prefix(int negative, t_token *token)
{
	if ((token->specs & F_ALT_FORM) && (token->specs & HEXAL))
	{
		if (token->specs & (ALL_CAPS))
			return ((int)write(1, "0X", 2));
		return ((int)write(1, "0x", 2));
	}
	if (negative)
		return ((int)write(1, "-", 1));
	if (token->specs & F_PRINT_PLUS)
		return ((int)write(1, "+", 1));
	if (token->specs & F_PADDED_POS)
		return ((int)write(1, " ", 1));
	return (0);
}


/* putstr prints the string representation of several conversions
 * that sometimes need to output string instead of what they usually do.
 * If minimum length is more than strings length, chars are
 * appended in front.
 */

int	putstr(const char *str, int min_len, char fill_char)
{
	int	len;
	int	ret;

	len = (int)ft_strlen(str);
	ret = 0;
	if (len < min_len)
		ret += ft_putset(min_len - len, fill_char);
	return (ret + (int)write(1, str, (size_t)len));
}

/* putfloat prints the required amount of digits from normalized float.
 * optionally last digit is rounded or trailing zeroes are trimmed.
 * mantissa is adjusted while printing, so this function can be called
 * repeatedly for the same float.
 *
 * But first, here's some utility functions.
 */

/* Actual powf is REAL complicated. It has specific edge cases that are
 * really counterintuitive and replicating it while staying within Norme
 * would be a lot of effort with little payoff. So I opted to make this
 * tiny version of it that is just used here in the context of putfloat.
 */

static long double	bad_powf(long double num, int exp)
{
	long double	out;

	if (exp <= 0)
		return (num);
	out = num;
	while (exp-- > 0)
		out *= num;
	return (out);
}

static int	prepare_float(long double *mantissa, ssize_t len, int round)
{
	long double	rd;
	int			ret;

	ret = 0;
	if (*mantissa < 0.0 || 42.0 / *mantissa == -1.0 / 0.0)
	{
		*mantissa = ft_fabsl(*mantissa);
		ret += ft_putchar('-');
	}
	if (len <= 0 || !round)
		return (ret);
	rd = 5.0L * bad_powf(0.1, (int)len - 1);
	if ((int)((*mantissa + rd) * bad_powf(10.0, (int)len - 2)) % 2 == 0)
		*mantissa += rd;
	return (ret);
}

int	putfloat(ssize_t len, long double *mantissa, int round, int trim)
{
	int	ipart;
	int	ret;
	int	ocount;

	ret = 0;
	ret += prepare_float(mantissa, len, round);
	ocount = 0;
	while (--len >= 0)
	{
		ipart = (int) *mantissa;
		*mantissa -= (long double) ipart;
		*mantissa *= 10.0;
		if (ipart == 0)
		{
			if (trim && len == 0)
				return (ret);
			ocount++;
			continue ;
		}
		else if (ocount > 0)
			ret += ft_putset(ocount, '0');
		ocount = 0;
		ret += ft_putchar('0' + (char)ipart);
	}
	return (ret + ft_putset(ocount, '0'));
}
