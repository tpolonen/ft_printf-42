/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/14 10:57:37 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_conversion(t_token *token, char **seek)
{
	static const char	conv[] = "cdieEfFgGosuxXpn%";
	int					i;

	i = 16;
	while (i >= 0)
	{
		if (**seek == conv[i])
		{
			token->specs |= 1 << (16 - i);
			return (0);
		}
		i--;
	}
	return (1);
}

static void	get_length(t_token *token, char **seek)
{
	int			i;
	int			len;
	const char	*length[] = {"h", "hh", "l", "ll", "j", "z", "t", "L"};

	i = 7;
	while (i >= 0)
	{
		len = ft_strlen(length[i]);
		if (ft_strncmp(*seek, length[i], len) == 0)
		{
			token->specs |= 1 << (7 - i);
			(*seek) += ft_strlen(length[i]);
			break ;
		}
		i--;
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
		i = 5;
		stop = 1;
		while (i >= 0)
		{
			if (**seek == flags[i])
			{
				token->specs |= 1 << (5 - i);
				stop = 0;
			}
			i--;
		}
		if (stop)
			break ;
		(*seek)++;
	}
	token->specs <<= 8;
}

static int	get_token(t_token *token, char **start, int *n, va_list args)
{
	get_flag(token, start);
	if (ft_isdigit(**start))
		token->width = (int) ft_strtol(*start, start);
	else if (**start == '*')
	{
		token->width = (int) va_arg(args, int);
		(*start)++;
	}
	if (**start == '.')
		token->precision = (int) ft_strtol(++(*start), start);	
	else if (**start == '*')
	{
		token->precision = (int) va_arg(args, int);
		(*start)++;
	}
	get_length(token, start);
	if (get_conversion(token, start))
		return (1);
	if (token->precision >= 0 || token->specs & F_RIGHT_PADDING)
		token->specs &= ~F_PAD_WITH_ZEROES;
	if (token->specs & F_RIGHT_PADDING)
		token->width = -(ft_abs(token->width));
	if (token->specs & PTR)
		token->specs |= F_ALT_FORM;
	return (0);
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
		token = (t_token){0, 0, -1};
		format++;
		if (get_token(&token, (char **) &format, &n, args) == 0)
			ret += dispatch(&token, args);
		else
			ret += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (ret);
}
