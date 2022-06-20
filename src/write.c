/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:18:12 by teppo             #+#    #+#             */
/*   Updated: 2022/06/20 22:31:09 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This is pretty kludgy attempt at saving lines from other int conversion
 * functions. Probably could be refactored in other existing functions somehow.
 * ._.
 */

int	print_prefix(int negative, t_token *token)
{
	if ((token->specs & F_ALT_FORM) && (token->specs & HEXAL))
	{
		if (token->specs & (ALL_CAPS))
			return (write(1, "0X", 2));
		return (write(1, "0x", 2));
	}
	if (negative)
		return (write(1, "-", 1));
	if (token->specs & F_PRINT_PLUS)
		return (write(1, "+", 1));
	if (token->specs & F_PADDED_POS)
		return (write(1, " ", 1));
	return (0);
}

/* putset works similarly to memset - char c is printed count times.
 * This form might be a bit overengineered, but at least it guarantees
 * that larger outputs are printed as fast as possible.
 */

int	putset(int count, char c)
{
	int		ret;
	char	buf[sizeof(size_t)];

	ret = 0;
	ft_memset(buf, c, sizeof(size_t));
	while (count > sizeof(size_t))
	{
		ret += write(1, buf, sizeof(size_t));
		count -= sizeof(size_t);
	}
	while (count > sizeof(int))
	{
		ret += write(1, buf, sizeof(int));
		count -= sizeof(int);
	}
	while (count)
	{
		ret += write(1, buf, 1);
		count -= 1;
	}
	return (ret);
}

/* putnum assembles the number as a string to buffer and outputs it.
 * If the minimum length is longer than amount of digits in number,
 * desired amount of zeroes is printed first and the buffer afterwards.
 */

int	putnum(size_t num, int base, int min_len, int all_caps)
{
	int			len;
	char		*digits;
	char		buf[30];
	int			i;
	int			ret;

	ret = 0;
	len = ft_sizelen(num, base);
	if (len < min_len)
		ret += putset(min_len - len, '0');
	i = len;
	if (all_caps)
		digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		digits = "0123456789abcdefghjiklmnopqrstuvwxyz";
	while (i > 0)
	{
		buf[--i] = digits[num % base];
		num /= base;
	}
	return (ret + write(1, buf, len));
}

/* putstr prints the string representation of inf/nan required
 * for floats, in uppercase or lowercase.
 * If minimum length is more than strings length, chars are
 * appended in front.
 */

int	putstr(const char *str, int min_len, char fill_char)
{
	int	len;
	int	ret;

	len = ft_strlen(str);
	ret = 0;
	if (len < min_len)
		ret += putset(min_len - len, fill_char);
	return (ret + write(1, str, len));
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
	if (round)
	{
		rd = 0.5;
		i = count;
		while (--i > 0)
			rd *= 0.1;
		*mantissa += rd;
	}
	while (count > 0)
	{
		ipart = (int) *mantissa;
		*mantissa -= (long double) ipart;
		ret += ft_putchar('0' + ipart);
		*mantissa *= 10.0;
		if (trim && *mantissa == 0.0)
			return (ret);
		count--;
	}
	return (ret);
}
