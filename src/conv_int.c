/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:12:55 by teppo             #+#    #+#             */
/*   Updated: 2022/06/08 11:14:34 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Conversion functions always return the amount of chars that were written,
 * or -1 in the case of error.
 */

static ssize_t	signed_typecast(t_token *token, va_list args)
{
	if (token->specs & S_CHAR)
		return ((ssize_t)(va_arg(args, int)) & CHAR_MASK) ;
	if (token->specs & SHORT)
		return ((ssize_t)va_arg(args, int) & SHORT_MASK);
	if (token->specs & LONG)
		return ((ssize_t)va_arg(args, long));
	if (token->specs & LLONG)
		return ((ssize_t)va_arg(args, long long));
	if (token->specs & SIZE_T)
		return (va_arg(args, ssize_t));
	if (token->specs & INTMAX_T)
		return ((ssize_t)va_arg(args, intmax_t));
	if (token->specs & PTRDIFF_T)
		return ((ssize_t)va_arg(args, ptrdiff_t));
	return ((ssize_t)va_arg(args, int) & INT_MASK);
}

static size_t	unsigned_typecast(t_token *token, va_list args)
{	
	if (token->specs & S_CHAR)
		return ((size_t)(unsigned char)va_arg(args, int));
	if (token->specs & SHORT)
		return ((size_t)(unsigned short)va_arg(args, int));
	if (token->specs & LONG)
		return ((size_t)(unsigned long)va_arg(args, unsigned long));
	if (token->specs & LLONG)
		return ((size_t)(unsigned long long)va_arg(args, unsigned long long));
	if (token->specs & SIZE_T)
		return (va_arg(args, size_t));
	if (token->specs & INTMAX_T)
		return ((size_t)va_arg(args, intmax_t));
	if (token->specs & PTRDIFF_T)
		return ((size_t)va_arg(args, ptrdiff_t));
	return ((size_t)(int)va_arg(args, int));
}

static int	check_base(t_token *token, int *base)
{
	int	ret;

	ret = 0;
	if (token->specs & OCTAL)
		*base = 8;
	else if (token->specs & HEXAL)
	{
		*base = 16;
		if (token->specs & F_ALT_FORM || token->specs & PTR)
		{
			if (token->specs & BIG_HEX)
				ret = write(1, "0X", 2);
			else
				ret = write(1, "0x", 2);
		}
	}
	else
		*base = 10;
	token->width -= ret;
	return (ret);
}

int	conv_integer(t_token *token, va_list args)
{
	ssize_t	ssize;
	size_t	usize;
	int		base;
	int		ret;

	if (token->specs & SIGNED)
	{
		ssize = signed_typecast(token, args, ft_);
		ret = check_base(token, &base);
		ret += putnum(ft_ssabs(ssize), ssize < 0, base, token);
	}
	else if (token->specs & UNSIGNED)
	{
		usize = unsigned_typecast(token, args);
		ret = check_base(token, &base);
		ret += putnum((size_t)usize, 0, base, token);
	}
 	return (ret);
}

