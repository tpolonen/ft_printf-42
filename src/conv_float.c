/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:25:27 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/17 17:41:35 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_sci_notation(long double num, int negative, int print, t_token *token)
{
	int		sign;
	size_t	exponent;
	size_t	significand;

	return (0);
}

static int	conv_dec_notation(long double num, int negative, int print, t_token *token)
{
	size_t		ipart;	
	long double	fpart;
	int			wlen;
	size_t		ret;
	int			flen;

	ipart = (size_t)num;
	fpart = num - (long double)ipart;
	wlen = ft_sizelen(ipart, 10) + 1 + token->precision;
	if (!print)
		return (wlen);
	ret = 0;
	if (token->width > 0)
		ret += putset(token->width - wlen, token->pchar);
	fpart *= ft_powl(10, token->precision);
	ret += (size_t)putnum(ipart, 10, 0, 0);
	ret += (size_t)write(1, ".", 1);
	flen = (size_t)putnum((size_t)fpart, 10, 0, 0);
	ret += flen;
//	printf("\nprecision %d flen %zu zeroes %d\n", token->precision, flen, (int)(token->precision - (int)flen));
	ret += putset(token->precision - flen, '0');
	return (ret);
}

static int	conv_shortest_float(long double num, int negative, t_token *token)
{
	return (0);
}

static int	check_expections(long double num, int *ret, t_token *token)
{
	*ret = 0;
	if (num != num)
		*ret = putstr("NaN", token);
	else if (num == num - num)
		*ret = putstr("inf", token);
	return (*ret);
}

int	conv_float(t_token *token, va_list args)
{
	long double	num;
	int			ret;
	int			negative;
	
	ret = 0;
	if (token->specs & LDOUBLE)
		num = va_arg(args, long double);
	else
		num = (long double)va_arg(args, double);
	if (check_expections(num, &ret, token))
		return (ret);
	if (num < 0.0)
	{
		negative = 1;
		num = ft_fabsl(num);
	}
	if (token->precision == -1)
		token->precision = 6;
	if (token->specs & SCI_DOUBLE)
		return (conv_sci_notation(num, negative, 1, token));
	else if (token->specs & DEC_DOUBLE)
		return (conv_dec_notation(num, negative, 1, token));
	else if (token->specs & SHORTEST_F)
		return (conv_shortest_float(num, negative, token));
	return (0);
}
