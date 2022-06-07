/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:12:55 by teppo             #+#    #+#             */
/*   Updated: 2022/06/07 12:57:26 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Conversion functions always return the amount of chars that were written,
 * or -1 in the case of error.
 */

/* putnum assembles the number as string to buffer, then writes the buffer.
 * If there is an appending character, it's added to front of the buffer
 * and rest of the characters are appended behind it.
 * Returns the amount of written characters.
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
		buf[0] = '-';
	else if (token->specs & F_PRINT_PLUS)
		buf[0] = '+';
	else if (token->specs & F_PADDED_POS)
		buf[0] = ' ';
	else
		i--;
	while (num > 0)
	{
		if (token->specs & BIG_HEX)
			buf[--i] = ft_toupper(digits[num % base]);
		else
			buf[--i] = digits[num % base];
		num /= base;
	}
	return (write(1, buf, len + (negative || token->specs & \
			(F_PRINT_PLUS | F_PADDED_POS))));
}

static ssize_t	signed_typecast(t_token *token, va_list args)
{
/*
	if (token->specs & S_CHAR)
		printf("?s_char?");
	if (token->specs & SHORT)
		printf("?short?");
	if (token->specs & LONG)
		printf("?long?");
	if (token->specs & LLONG)
		printf("?llong?");
	if (token->specs & SIZE_T)
		printf("?size_t?");
	if (token->specs & INTMAX_T)
		printf("?intmax_t?");
	if (token->specs & PTRDIFF_T)
		printf("?ptrdiff_tt?");
*/
	if (token->specs & S_CHAR)
		return ((ssize_t)(signed char)va_arg(args, int));
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
	size_t	size;
	int		base;
	int		ret;
	int		len;

	if (token->specs & SIGNED)
	{
		size = (size_t)signed_typecast(token, args);
		ret = check_base(token, &base);
		len = token->width - (int)ft_ssizelen((ssize_t)size, base);
		len += (token->specs & F_PADDED_POS || token->specs & F_PRINT_PLUS);
		printf("<%d>", len);
//		ret += print_padding(len, token->pad_char, args);
		ret += putnum(ft_ssabs((ssize_t)size), (ssize_t)size < 0, base, token);
	}
	else if (token->specs & UNSIGNED)
	{
		size = unsigned_typecast(token, args);
		ret = check_base(token, &base);
		ret += putnum(size, 0, base, token);
	}
 	return (ret);
}

