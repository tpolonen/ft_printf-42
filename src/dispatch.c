/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:41:23 by teppo             #+#    #+#             */
/*   Updated: 2022/06/08 12:48:21 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_char(t_token *token, va_list args)
{
	char	c;
	int		len;

	len = 1;
	if (token->specs & U_CHAR)
		c = va_arg(args, int);
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
	if (token->precision >= 0 && token->precision > len)
		len = token->precision;
	write(1, str, len);
	return (len);
}

int	dispatch(t_token *token, va_list args)
{
	int				i;
	int				ret;
	const t_conv	conv_table[] = {\
	{INTEGER, &conv_integer}, {U_CHAR | PERCENT, &conv_char},\
	{FLOAT, &conv_float}, {CHAR_ARR, &conv_string}
	};
	const int		func_count = sizeof(conv_table) / sizeof(t_conv);

	i = 0;
	ret = 0;
	while (i < func_count)
	{
		if (token->specs & conv_table[i].key)
			ret += conv_table[i].func(token, args);
		i++;
	}
	if (token->width > ret)
	//	ret+ = print_padding(token->width - ret, token->pad_char, args);
		;
	return (ret);
}
