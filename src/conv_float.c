/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:25:27 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/16 14:57:55 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_sci_notation(long double num, t_token *token)
{
	int		sign;
	size_t	exponent;
	size_t	mantissa;

	return (0);
}

int	conv_dec_notation(long double num, t_token *token)
{
	return (0);
}

int	conv_shortest_float(long double num, t_token *token)
{
	return (0);
}

int	conv_float(t_token *token, va_list args)
{
	long double	num;

	if (token->specs & LDOUBLE)
		num = va_arg(args, long double);
	else
		num = (long double)va_arg(args, long double);
	if (token->specs & SCI_DOUBLE)
		return (conv_sci_notation(num, token);
	else if (token->specs & DEC_DOUBLE)
		return (conv_dec_notation(num, token);
	else if (token->specs & SHORTEST_F)
		return (conv_shortest_float(num, token);
	return (0);
}
