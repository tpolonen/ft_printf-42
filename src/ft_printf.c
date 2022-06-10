/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/10 18:24:56 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_conversion(t_token *token, char **seek)
{
	static const char	conv[] = "cdieEfFgGosuxXpn%";
	int	i;

	i = 0;
	while (i < 17)
	{
		if (**seek == conv[17 - i - 1])
		{
			token->specs |= 1 << i;
			return (1);
		}
		i++;
	}
	return (0);
}

static void	get_length(t_token *token, char **seek)
{
	int			i;
	int			len;
	const char	*length[] = {"h", "hh", "l", "ll", "j", "z", "t", "L"};

	i = 0;
	while (i < 8)
	{
		len = ft_strlen(length[8 - i - 1]);
		if (ft_strncmp(*seek, length[8 - i - 1], len) == 0)
		{
			token->specs |= 1 << i;
			(*seek) += ft_strlen(length[8 - i - 1]);
			break ;
		}
		i++;
	}
	token->specs <<= 17;
}

static void	get_flag(t_token *token, char **seek)
{
	int			i;
	int			stop;
	const char	flags[] = "*-+ #0";

	while (**seek != '\0')
	{
		i = 0;
		stop = 1;
		while (i < 6)
		{
			if (**seek == flags[6 - i - 1])
			{
				token->specs |= (1 << i);
				stop = 0;
			}
			i++;
		}
		if (stop)
			break ;
		(*seek)++;
	}
	token->specs <<= 8;
}

static int	get_token(t_token *token, char **start, int *n)
{
	char	*begin;

	begin = (*start)++;
	get_flag(token, start);
	if (ft_isdigit(**start))
		token->width = (int) ft_strtol(*start, start);
	if (**start == '.')
		token->precision = (int) ft_strtol(++(*start), start);
	get_length(token, start);
	if (!get_conversion(token, start))
	{
		write(1, "%", 1);
		*start = begin;
		return (0);
	}
	if (token->precision == 0 && token->specs & F_PAD_WITH_ZEROES && \
			!(token->specs & F_RIGHT_PADDING))
		token->pad_char = '0';
	else
		token->pad_char = ' ';
	if (token->specs & F_RIGHT_PADDING)
		token->width = -(ft_abs(token->width));
	if (token->specs & PTR)
		token->specs |= F_ALT_FORM;
	return (token->specs != 0);
}

/*
 * 1. Write characters from format sign until null byte or '%' is reached.
 * 2. Turn conversion into token, containing bitflags, width and precision.
 *    ...if that fails, conversion is invalid. Just write the next char.
 * 3. Send token and argument list to converter.
 * 4. Converter forwards token and argument list to correct function.
 * 5. If there's left padding,  print it now.
 * 6. Function will convert argument to correct output and return
 *    the amount of bytes that were printed.
 * 7. If there's right padding, print it now.
 * 8. Repeat until null byte is reached.
 * 9. Return how many characters were written in total.
 */

int	ft_printf(const char *restrict format, ...)
{
	va_list	args;
	t_token	token;
	int		n;
	int		ret;

	va_start(args, format);
	ret = 0;
	while (*format != '\0')
	{
		n = 0;
		while (format[n] != '%' && format[n] != '\0')
			n++;
		ret += n;
		format += write(1, format, n);
		if (*format == '\0')
			break ;
		token = (t_token){0, 0, 0, '\0'};
		if (get_token(&token, (char **) &format, &n))
			ret += dispatch(&token, args);
		else
			ret++;
		format++;
	}
	va_end(args);
	return (ret);
}
