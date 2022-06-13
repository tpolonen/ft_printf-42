/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:41:23 by teppo             #+#    #+#             */
/*   Updated: 2022/06/13 19:40:54 by tpolonen         ###   ########.fr       */
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
	int				ret;

	ret = 0;
	if (token->specs & U_CHAR)
		c = (unsigned char) va_arg(args, int);
	else
		c = '%';
	if (token->width > 1 && !(token->specs & F_RIGHT_PADDING))
		ret += putset(token->width - 1, ' ');
	return (ret + write(1, &c, 1));
}

int	conv_string(t_token *token, va_list args)
{	
	char	*str;
	int		len;
	int		ret;

	len = 0;
	ret = 0;
	str = va_arg(args, char *);
	while (str[len])
		len++;
	if (token->precision >= 0 && token->precision < len)
		len = token->precision;
	if (len < token->width && !(token->specs & F_RIGHT_PADDING))
		ret += putset(token->width - len, ' ');
	ret += write(1, str, len);
	return (ret);
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
		{
			ret += g_conv_table[i].func(token, args);
			break ;
		}
		i++;
	}
	if ((token->specs & F_RIGHT_PADDING) && ft_abs(token->width) > ret)
		ret += putset(token->width + ret, ' ');
	return (ret);
}
