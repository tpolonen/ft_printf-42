/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:18:12 by teppo             #+#    #+#             */
/*   Updated: 2022/06/13 20:04:10 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prefix(int negative, t_token *token)
{
	if ((token->specs & HEXAL && token->specs & F_ALT_FORM) || \
			token->specs & PTR)
	{
		if (token->specs & ALL_CAPS)
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
 * If the minimum length is longer than amount of digits in number,,
 * desired amount of zeroes is printed first and the buffer afterwards.
 */

int	putnum(size_t num, int base, int min_len, int all_caps)
{
	int			len;
	const char	digits[] = "0123456789abcdefghjiklmnopqrstuvwxyz";
	char		buf[30];
	int			i;
	int			ret;

	ret = 0;
	len = ft_sizelen(num, base);
	if (len < min_len)
		ret += putset(min_len - len, '0');
	i = len;
	while (i > 0)
	{
		if (all_caps)
			buf[--i] = ft_toupper(digits[num % base]);
		else
			buf[--i] = digits[num % base];
		num /= base;
	}
	return (ret + write(1, buf, len));
}
