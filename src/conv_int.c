/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:41:07 by tpolonen          #+#    #+#             */
/*   Updated: 2022/07/02 21:50:08 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* These typecasts are needed to replicate the authentic behaviour of
 * over/underflowing integer conversions. If you send INTMAX to signed char
 * conversion, you want output to be value between -128 - 127 and so on.
 */

static ssize_t	signed_typecast(t_token *token, va_list args)
{
	if (token->specs & S_CHAR)
		return ((ssize_t)(signed char)(va_arg(args, int)));
	if (token->specs & SHORT)
		return ((ssize_t)(signed short)va_arg(args, int));
	if (token->specs & LONG)
		return ((ssize_t)(signed long)va_arg(args, long));
	if (token->specs & LLONG)
		return ((ssize_t)(signed long long)va_arg(args, long long));
	if (token->specs & SIZE_T)
		return (va_arg(args, ssize_t));
	if (token->specs & INTMAX_T)
		return ((ssize_t)va_arg(args, intmax_t));
	if (token->specs & PTRDIFF_T)
		return ((ssize_t)va_arg(args, ptrdiff_t));
	return ((ssize_t)(signed int)va_arg(args, int));
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
	return ((size_t)(unsigned int)va_arg(args, int));
}

static int	get_prefix_len(int negative, t_token *token)
{
	if ((token->specs & HEXAL) && (token->specs & F_ALT_FORM))
		return (2);
	if (negative || token->specs & F_PADDED_POS || token->specs & F_PRINT_PLUS)
		return (1);
	return (0);
}

/* In this context prefix means everything that comes before the actual number:
 * padding with whitespace or zeroes and optional plus/minus/empty space for
 * sign.
 *
 * Order of operation matters: If we pad width with zeroes, we print signs
 * first and zeroes after them - [+0009] for example.
 * When we pad with whitespace, order is reversed - [   +9] for example.
 */

static int	check_prefix(t_token *token, int len, int negative)
{
	int	ret;
	int	pre_len;
	int	pre_printed;

	ret = 0;
	pre_len = get_prefix_len(negative, token);
	pre_printed = 0;
	if (len > token->precision)
		token->precision = len;
	if ((token->specs & OCTAL) && (token->specs & F_ALT_FORM))
		token->precision = ft_max(token->precision, len + 1);
	if ((token->precision + pre_len) > token->width || token->pchar == '0')
	{
		ret += print_prefix(negative, token);
		pre_printed = 1;
	}
	if ((token->precision + pre_len) < token->width)
		ret += ft_putset(token->width - token->precision - pre_len,
				token->pchar);
	if (pre_len > 0 && pre_printed == 0)
		ret += print_prefix(negative, token);
	return (ret);
}

int	conv_integer(t_token *token, va_list args)
{
	ssize_t	ssize;
	size_t	usize;
	int		base;
	int		ret;
	size_t	len;

	ssize = 0;
	base = 10;
	if (token->specs & OCTAL)
		base = 8;
	else if (token->specs & HEXAL)
		base = 16;
	if (token->specs & SIGNED)
	{
		ssize = signed_typecast(token, args);
		usize = ft_ssabs(ssize);
	}
	else if (token->specs & UNSIGNED)
		usize = unsigned_typecast(token, args);
	if (token->specs & PTR && usize == 0)
		return (putstr("(nil)", token->width, ' '));
	len = ft_sizelen(usize, base);
	ret = check_prefix(token, (int)len, ssize < 0);
	ret += ft_putnum(usize, base, token->precision, token->specs & ALL_CAPS);
	return (ret);
}
