/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:12:55 by teppo             #+#    #+#             */
/*   Updated: 2022/06/02 18:08:13 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_handler(t_dstr **out, int token, va_list args)
{
	if (token & SIGNED) ft_dstrbuild(out, "signed ", 7);
	else if (token & UNSIGNED) ft_dstrbuild(out, "unsigned ", 9);

	if (token & DECIMAL) ft_dstrbuild(out, "decimal ", 8);
	else if (token & OCTAL) ft_dstrbuild(out, "octal ", 7);
	else if (token & HEXAL) ft_dstrbuild(out, "hexadecimal ", 12);

	if (token & LLONG) ft_dstrbuild(out, "long long!", 11);
//		ll_handler(t_dstr out, token, va_arg(args, long long));
	else if (token & LONG) ft_dstrbuild(out, "long!", 6);
//		l_handler(t_dstr out, token, va_arg(args, long));
	else ft_dstrbuild(out, "integer!", 9);
	return (0);
}

int	char_handler(t_dstr **out, int token, va_list args)
{
	char	*str;

	if (token & U_CHAR)
		ft_dstraddc(out, (unsigned char) va_arg(args, int));
	else if (token & CHAR_ARR)
	{
		str = va_arg(args, char *);
		while (*str)
			ft_dstraddc(out, *str++);
	}
	else if (token & PERCENT)
		ft_dstraddc(out, '%');
	return (0);
}

int float_handler(t_dstr **out, int token, va_list args)
{
	if (token & SCI_DOUBLE) ft_dstrbuild(out, "double! (scientific notation)", 30);
	else if (token & DEC_DOUBLE) ft_dstrbuild(out, "double! (decimal notation)", 27);
	else if (token & SHORTEST_F) ft_dstrbuild(out, "double! (shortest notation)", 28);
	return (0);
}
