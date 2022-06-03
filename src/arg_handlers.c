/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:12:55 by teppo             #+#    #+#             */
/*   Updated: 2022/06/03 14:03:03 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Handlers always return the amount of chars that were added to dynamic string,
 * or -1 in the case of error.
 */

int	int_handler(t_dstr **out, t_token *token, va_list args)
{
	if (token->specs & SIGNED) ft_dstrbuild(out, "signed ", 7);
	else if (token->specs & UNSIGNED) ft_dstrbuild(out, "unsigned ", 9);

	if (token->specs & DECIMAL) ft_dstrbuild(out, "decimal ", 8);
	else if (token->specs & OCTAL) ft_dstrbuild(out, "octal ", 7);
	else if (token->specs & HEXAL) ft_dstrbuild(out, "hexadecimal ", 12);

	if (token->specs & LLONG) ft_dstrbuild(out, "long long!", 11);
	else if (token->specs & LONG) ft_dstrbuild(out, "long!", 6);
	else ft_dstrbuild(out, "integer!", 9);
	return (0);
}

int	char_handler(t_dstr **out, t_token *token, va_list args)
{
	char	*str;
	int		count;

	if (token->specs & U_CHAR || token->specs & PERCENT)
	{
		if (token->specs & U_CHAR)
			ft_dstraddc(out, (unsigned char) va_arg(args, int));
		else
			ft_dstraddc(out, '%');
		return (1);
	}
	str = va_arg(args, char *);
	count = 0;
	while (str[count])
		ft_dstraddc(out, str[count++]);
	return (count);
}

int float_handler(t_dstr **out, t_token *token, va_list args)
{
	if (token->specs & SCI_DOUBLE) ft_dstrbuild(out, \
			"double! (scientific notation)", 30);
	else if (token->specs & DEC_DOUBLE) ft_dstrbuild(out, \
			"double! (decimal notation)", 27);
	else if (token->specs & SHORTEST_F) ft_dstrbuild(out, \
			"double! (shortest notation)", 28);
	return (0);
}
