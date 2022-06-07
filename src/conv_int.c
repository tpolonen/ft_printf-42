/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:12:55 by teppo             #+#    #+#             */
/*   Updated: 2022/06/07 07:06:42 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Conversion functions always return the amount of chars that were written,
 * or -1 in the case of error.
 */

static int	putnum(size_t num, int negative, int base, t_token *token)
{
	size_t		len;
	const char	digits[] = "0123456789abcdefghjiklmnopqrstuvwxyz";
	char		buf[30];
	int			i;

	len = ft_sizelen(num, base);
	i = len + 1;
	if (negative)
		buf[--i] = '-';
	else if (token->specs & F_PRINT_PLUS)
		buf[--i] = '+';
	else if (token->specs & F_PADDED_POS)
		buf[--i] = ' ';
	else
		--i;
	while (num > 0)
	{
		if (token->specs & BIG_HEX)
			buf[--i] = ft_toupper(digits[num % base]);
		else
			buf[--i] = digits[num % base];
		num /= base;
	}
	write(1, buf, len);
	return (len + (negative || token->specs & F_PRINT_PLUS & F_PADDED_POS));
}

static ssize_t	signed_typecast(t_token *token, va_list args)
{
	if (token->specs & S_CHAR)
		return ((ssize_t)(signed char)va_arg(args, int));
	if (token->specs & SHORT)
		return ((ssize_t)(signed short)va_arg(args, int));
	if (token->specs & LONG)
		return ((ssize_t)(signed long)va_arg(args, signed long));
	if (token->specs & LLONG)
		return ((ssize_t)(signed long long)va_arg(args, signed long long));
	if (token->specs & SIZE_T)
		return (va_arg(args, ssize_t));
	if (token->specs & INTMAX_T)
		return ((ssize_t)va_arg(args, intmax_t));
	if (token->specs & PTRDIFF_T)
		return ((ssize_t)va_arg(args, ptrdiff_t));
	return ((ssize_t)(int)va_arg(args, int));
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
	return ((ssize_t)(int)va_arg(args, int));
}

static int	check_base(t_token *token, int *base, int negative)
{
	int	ret;

	ret = 2;
	if (token->specs & OCTAL)
		*base = 8;
	else if (token->specs & HEXAL)
		*base = 16;
	else
		*base = 10;
	if (token->specs & BIG_HEX && token->specs & F_ALT_FORM)
		write(1, "0X", 2);
	else if (token->specs & HEXAL && \
			(token->specs & F_ALT_FORM || token->specs & PTR))
		write(1, "0x", 2);
	else
		ret = 0;
	token->width -= ret;
	return (ret);
}

int	conv_integer(t_token *token, va_list args)
{
	size_t	usize;
	ssize_t	ssize;
	int		base;
	int		ret;

	if (token->specs & SIGNED)
	{
		ssize = signed_typecast(token, args);
		ret = check_base(token, &base, ssize < 0);
		ret += putnum(ft_ssabs(ssize), ssize < 0, base, token);
	}
	else if (token->specs & UNSIGNED)
	{
		usize = unsigned_typecast(token, args);
		ret = check_base(token, &base, 0);
		ret += putnum(usize, 0, base, token);
	}
 	return (ret);
}

