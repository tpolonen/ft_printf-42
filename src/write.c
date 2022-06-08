/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:18:12 by teppo             #+#    #+#             */
/*   Updated: 2022/06/08 11:14:34 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* putnum assembles the number as string to buffer, then writes the buffer.
 * If there is an appending character, it's added to front of the buffer
 * and rest of the characters are appended behind it.
 * Returns the amount of written characters.
 */
int	putnum(size_t num, int negative, int base, t_token *token)
{
	size_t		len;
	const char	digits[] = "0123456789abcdefghjiklmnopqrstuvwxyz";
	char		buf[30];
	int			i;

	len = ft_sizelen(num, base);
	i = len + 1;
	if (negative)
		buf[0] = '-';
	else if (token->specs & F_PRINT_PLUS)
		buf[0] = '+';
	else if (token->specs & F_PADDED_POS)
		buf[0] = ' ';
	else
		i--;
	while (num > 0)
	{
		if (token->specs & BIG_HEX)
			buf[--i] = ft_toupper(digits[num % base]);
		else
			buf[--i] = digits[num % base];
		num /= base;
	}
	return (write(1, buf, len + (negative || token->specs & \
			(F_PRINT_PLUS | F_PADDED_POS))));
}

int	print_padding(int count, char c, va_list args)
{
	int	ret;

	ret = 0;
	while (count)
	{
		ret += write(1, &c, 1);
		count--;
	}
	return (ret);
}

