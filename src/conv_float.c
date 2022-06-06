/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:25:27 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/06 18:04:42 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_float(t_token *token, va_list args)
{
	if (token->specs & SCI_DOUBLE)
		write(1, "double! (scientific notation)", 30);
	else if (token->specs & DEC_DOUBLE)
		write(1, "double! (decimal notation)", 27);
	else if (token->specs & SHORTEST_F)
		write(1, "double! (shortest notation)", 28);
	return (0);
}
