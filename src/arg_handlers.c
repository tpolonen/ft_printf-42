/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:12:55 by teppo             #+#    #+#             */
/*   Updated: 2022/06/06 15:23:40 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Conversion functions always return the amount of chars that were written,
 * or -1 in the case of error.
 */

static int	putnum(size_t num, int negative, int base)
{
	size_t	len;
	char	digits[] = "0123456789abcdefghjiklmnopqrstuvwxyz";

	len = ft_sizelen(num, base);
	if (negative)
		write(1, "-", 1);
	while (num > 0)
	{
		write(1, &digits[num % base], 1);
		num /= base;
	}
	return (len);
}

static ssize_t	signed_typecast(t_token *token, va_list args)
{
	if (token->specs & S_CHAR)
		return ((ssize_t)(signed char)va_arg(args, int));
	if (token->specs & SHORT)
		return ((ssize_t)(short)va_arg(args, int));
	if (token->specs & LONG)
		return ((ssize_t)(long)va_arg(args, long));
	if (token->specs & LLONG)
		return ((ssize_t)(long long)va_arg(args, long long));
	if (token->specs & SIZE_T)
		return ((ssize_t)va_arg(args, size_t));
	if (token->specs & INTMAX_T)
		return ((ssize_t)va_arg(args, intmax_t));
	if (token->specs & PTRDIFF_T)
		return ((ssize_t)va_arg(args, ptrdiff_t));
	return ((ssize_t)(int)va_arg(args, int));
}

static size_t	unsigned_typecast(t_token *token, va_list args)
{	
	if (token->specs & S_CHAR)
		return ((ssize_t)(signed char)va_arg(args, int));
	if (token->specs & SHORT)
		return ((size_t)(short)va_arg(args, int));
	if (token->specs & LONG)
		return ((size_t)(long)va_arg(args, long));
	if (token->specs & LLONG)
		return ((size_t)(long long)va_arg(args, long long));
	if (token->specs & SIZE_T)
		return ((size_t)va_arg(args, size_t));
	if (token->specs & INTMAX_T)
		return ((size_t)va_arg(args, intmax_t));
	if (token->specs & PTRDIFF_T)
		return ((size_t)va_arg(args, ptrdiff_t));
	return ((ssize_t)(int)va_arg(args, int));
}

int	conv_integer(t_token *token, va_list args)
{
	size_t	usize;
	ssize_t	ssize;
	int		base;

	if (token->specs & SIGNED)
	{
		ssize = signed_typecast(token, args);
		return (putnum(ft_llabs(ssize), ssize < 0, base));
	}
	if (token->specs & UNSIGNED)
	{
		usize = unsigned_typecast(token, args);
		return (putnum(usize, 0, base));
	}
}

int	conv_char(t_token *token, va_list args)
{
	char	*str;
	int		len;

	len = 0;
	if (token->specs & U_CHAR || token->specs & PERCENT)
	{
		if (token->specs & U_CHAR)
		{
			len = va_arg(args, int);
			write(1, (unsigned char *) &(len), 1);
		}
		else
			write(1, "%", 1);
		return (1);
	}
	str = va_arg(args, char *);
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

int conv_float(t_token *token, va_list args)
{
	if (token->specs & SCI_DOUBLE) write(1, \
			"double! (scientific notation)", 30);
	else if (token->specs & DEC_DOUBLE) write(1, \
			"double! (decimal notation)", 27);
	else if (token->specs & SHORTEST_F) write(1, \
			"double! (shortest notation)", 28);
	return (0);
}
