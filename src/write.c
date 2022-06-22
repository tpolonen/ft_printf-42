/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:18:12 by teppo             #+#    #+#             */
/*   Updated: 2022/06/22 23:09:53 by teppo            ###   ########.fr       */
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
 */

int	putfloat(ssize_t count, long double *mantissa, int round, int trim)
{
	int		ipart;
	int		ret;
	int		i;
	double	rd;

	ret = 0;
	if (round && count > 0)
	{
		rd = 5.0;
		i = (int)count;
		while (i-- > 0)
			rd *= 0.1;
		*mantissa += rd;
	}
	if (*mantissa < 0.0 || 42.0 / *mantissa == -1.0 / 0.0)
		ret += ft_putchar('-');
	*mantissa = ft_fabsl(*mantissa);
	while (--count >= 0)
	{
		ipart = (int) *mantissa;
		*mantissa -= (long double) ipart;
		ret += ft_putchar('0' + (char)ipart);
		*mantissa *= 10.0;
		if (trim && *mantissa == 0.0)
			return (ret);
	}
	return (ret);
}
