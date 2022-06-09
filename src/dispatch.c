/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:41:23 by teppo             #+#    #+#             */
/*   Updated: 2022/06/09 19:53:07 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_conv	g_conv_table[] = {
{INTEGER, &conv_integer},
{U_CHAR | PERCENT, &conv_char},
{FLOAT, &conv_float},
{CHAR_ARR, &conv_string}
};

int	conv_char(t_token *token, va_list args)
{
	unsigned char	c;

	if (token->specs & U_CHAR)
		c = (unsigned char) va_arg(args, int);
	else
		c = '%';
	return (write(1, &c, 1));
}

int	conv_string(t_token *token, va_list args)
{	
	char	*str;
	int		len;

	len = 0;
	str = va_arg(args, char *);
	while (str[len])
		len++;
	if (token->precision > 0 && token->precision < len)
		len = token->precision;
	write(1, str, len);
	return (len);
}

int	dispatch(t_token *token, va_list args)
{
	int				i;
	int				ret;
	const int		func_count = sizeof(g_conv_table) / sizeof(t_conv);

	i = 0;
	ret = 0;
	while (i < func_count)
	{
		if (token->specs & g_conv_table[i].key)
			ret += g_conv_table[i].func(token, args);
		i++;
	}
	return (ret);
}
