/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:12:55 by teppo             #+#    #+#             */
/*   Updated: 2022/06/06 12:42:28 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Conversion functions always return the amount of chars that were written,
 * or -1 in the case of error.
 */

static int	putnum(ssize_t num, int sign, int base)
{
	size_t	len;
	int		i;
	char	buf[30];
	char	digits[] = "0123456789abcdefghjiklmnopqrstuvwxyz";

	i = 0;
	if (num < 0)
		buf[i++] = '-';

}

int	conv_integer(t_token *token, va_list args)
{
	if (token->specs & SIGNED) write(1, "signed ", 7);
	else if (token->specs & UNSIGNED) write(1, "unsigned ", 9);

	if (token->specs & DECIMAL) write(1, "decimal ", 8);
	else if (token->specs & OCTAL) write(1, "octal ", 7);
	else if (token->specs & HEXAL) write(1, "hexadecimal ", 12);

	if (token->specs & LLONG) write(1, "long long!", 11);
	else if (token->specs & LONG) write(1, "long!", 6);
	else write(1, "integer!", 9);
	return (0);
}

int	conv_char(t_token *token, va_list args)
{
	char	*str;
	int		len;

	len = 0;
	if (token->specs & U_CHAR || token->specs & PERCENT)
	{
		if (token->specs & U_CHAR)
		{
			len = va_arg(args, int);
			write(1, (unsigned char *) &(len), 1);
		}
		else
			write(1, "%", 1);
		return (1);
	}
	str = va_arg(args, char *);
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

int conv_float(t_token *token, va_list args)
{
	if (token->specs & SCI_DOUBLE) write(1, \
			"double! (scientific notation)", 30);
	else if (token->specs & DEC_DOUBLE) write(1, \
			"double! (decimal notation)", 27);
	else if (token->specs & SHORTEST_F) write(1, \
			"double! (shortest notation)", 28);
	return (0);
}
