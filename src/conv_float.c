/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:25:27 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/16 20:21:43 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_sci_notation(long double num, int print, t_token *token)
{
	int		sign;
	size_t	exponent;
	size_t	significand;

	return (0);
}

static int	conv_dec_notation(long double num, int print, t_token *token)
{
	size_t		ipart;	
	long double	fpart;
	int			flen;
	int			wlen;
	int			ret;

	printf("whats the num %Lf\n", num);
	ipart = (size_t)num;
	printf("whats ipart %zu\n", ipart);
	fpart = num - (long double)ipart;
	printf("franctions should be %Lf\n", fpart);
	while (fpart > 0.0)
	{
		printf("franctions should be %Lf\n", fpart);
		fpart *= 10.0;
	}
	printf("franctions should be %Lf\n", fpart);
	flen = (int)ft_sizelen(fpart, 10);
	wlen = ft_sizelen(ipart, 10) + 1 + flen + ft_max(0, (token->precision - flen));
	if (!print)
		return (wlen);
	ret = 0;
	if (token->width > 0)
		ret += putset(token->width - wlen, token->pchar);
	ret += putnum(ipart, 10, 0, 0);
	ret += write(1, ".", 1);
	ret += putnum(fpart, 10, 0, 0);
	ret += putset(token->precision - fpart, '0');
	return (ret);
}

static int	conv_shortest_float(long double num, t_token *token)
{
	return (0);
}

int	conv_float(t_token *token, va_list args)
{
	long double	num;

	if (token->specs & LDOUBLE)
		num = va_arg(args, long double);
	else
		num = (long double)va_arg(args, double);
	if (num != num)
		return (putstr("NaN", token));
	if (num == (1.0 / 0.0))
		return (putstr("inf", token));
	if (token->precision == -1)
		token->precision = 6;
	if (token->specs & SCI_DOUBLE)
		return (conv_sci_notation(num, 1, token));
	else if (token->specs & DEC_DOUBLE)
		return (conv_dec_notation(num, 1, token));
	else if (token->specs & SHORTEST_F)
		return (conv_shortest_float(num, token));
	return (0);
}
