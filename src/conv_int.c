/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:12:55 by teppo             #+#    #+#             */
/*   Updated: 2022/06/08 12:49:24 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Conversion functions always return the amount of chars that were written,
 * or -1 in the case of error.
 */

static ssize_t	signed_typecast(t_token *token, va_list args)
{
	if (token->specs & S_CHAR)
		return ((ssize_t)(va_arg(args, int))) ;
	if (token->specs & SHORT)
		return ((ssize_t)va_arg(args, int));
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
	return ((ssize_t)va_arg(args, int));
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

static int	get_base(t_token *token)
{
	if (token->specs & OCTAL)
		return (8);
	else if (token->specs & HEXAL)
		return (16);
	else
		return (10);
}

int	conv_integer(t_token *token, va_list args)
{
	ssize_t	ssize;
	size_t	usize;
	int		base;
	int		ret;
	size_t	len;

	base = get_base(token);
	if (token->specs & SIGNED)
	{
		ssize = signed_typecast(token, args);
		len = ft_ssizelen(ssize, base) + ret;
		if (token->width > 0 && len < token->width)
			ret += print_padding(token->width - len, token, args); 
		ret += putnum(ft_ssabs(ssize), ssize < 0, base, token);
	}
	else if (token->specs & UNSIGNED)
	{
		usize = unsigned_typecast(token, args);
		len = ft_sizelen(usize, base) + ret;
		if (token->width > 0 && len < token->width)
			ret += print_padding(token->width - len, token, args); 
		ret += putnum((size_t)usize, 0, base, token);
	}
 	return (ret);
}

