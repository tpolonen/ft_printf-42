/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:18:12 by teppo             #+#    #+#             */
/*   Updated: 2022/06/10 12:03:59 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prefix(int negative, t_token *token)
{
	int	ret;

	ret = 0;
	if ((token->specs & HEXAL && token->specs & F_ALT_FORM) || token->specs & PTR)
	{
		if (token->specs & ALL_CAPS)
			ret += write(1, "0X", 2);
		else
			ret += write(1, "0x", 2);
	}
	else if (negative)
		ret += write(1, "-", 1);
	else if (token->specs & F_PRINT_PLUS)
		ret += write(1, "+", 1);
	else if (token->specs & F_PADDED_POS)
		ret += write(1, " ", 1);
	return (ret);
}

int	print_padding(int count, t_token *token, va_list args)
{
	int	ret;

	(void) args;
	ret = 0;
//	printf("[%d%c]", count, token->pad_char);
	while (count > 0)
	{
//		printf("[%d%c]", count, token->pad_char);
		ret += write(1, &(token->pad_char), 1);
		count--;
	}
	return (ret);
}

/* putnum assembles the number as string to buffer, then writes the buffer.
 * If there is an appending character, it's added to front of the buffer
 * and rest of the characters are appended behind it.
 * Returns the amount of written characters.
 */

int	putnum(size_t num, int base, int min_len, int all_caps)
{
	int			len;
	const char	digits[] = "0123456789abcdefghjiklmnopqrstuvwxyz";
	char		buf[30];
	int			i;

	len = ft_sizelen(num, base);
	if (len < min_len)
		len = min_len;
	i = len;
	while (i > 0)
	{
		if (all_caps)
			buf[--i] = ft_toupper(digits[num % base]);
		else
			buf[--i] = digits[num % base];
		num /= base;
	}
	return (write(1, buf, len));
}
