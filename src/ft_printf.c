/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/06 17:28:39 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_conv	g_conv_table[] = {\
	{INTEGER, &conv_integer}, {CHAR, &conv_char}, {FLOAT, &conv_float}
};
static const int	g_func_count = sizeof(g_conv_table) / sizeof(t_conv);
static const char	g_flags[] = "-+ #0";
static const int	g_flag_count = 5;
static const char	*g_length[] = {
	"h",
	"hh",
	"l",
	"ll",
	"j",
	"z",
	"t",
	"L"
};
static const int	g_length_count = 8;
static const char	g_conv[] = "cdieEfFgGosuxXpn%";
static const int	g_conv_count = 17;

static void	get_conv(t_token *token, char **seek)
{
	int	i;

	i = 0;
	while (i < g_length_count)
	{
		if (ft_strncmp(*seek, g_length[g_length_count - i - 1], \
					ft_strlen(g_length[g_length_count - i - 1])) == 0)
		{
			token->specs |= 1 << i;
			(*seek) += ft_strlen(g_length[g_length_count - i - 1]);
			break ;
		}
		i++;
	}
	token->specs <<= g_conv_count;
	i = 0;
	while (i < g_conv_count)
	{
		if (**seek == g_conv[g_conv_count - i - 1])
		{
			token->specs |= (1 << i);
			break ;
		}
		i++;
	}
}

static void	get_flag(t_token *token, char **seek)
{
	int	i;
	int	stop;

	while (**seek != '\0')
	{	
		i = 0;
		stop = 1;
		while (i < g_flag_count)
		{
			if (**seek == g_flags[g_flag_count - i - 1])
			{
				token->specs |= 1 << i;
				stop = 0;
			}
			i++;
		}
		if (stop)
			break ;
		(*seek)++;
	}
	token->specs <<= g_length_count;
}

static int	get_token(t_token *token, char **start, int *n)
{
	*token = (t_token){0, 0, 0};
	if (*(*start)++ != '%')
	{
		write(1, start, (*n)++);
		return (0);
	}
	get_flag(token, start);
	if (ft_isdigit(**start))
		token->width = (int) ft_strtol(*start, start);
	if (**start == '.')
	{
		(*start)++;
		token->precision = (int) ft_strtol(*start, start);
	}
	get_conv(token, start);
	return (token->specs != 0);
}

static int	convert(t_token *token, va_list args)
{
	int	i;

	i = 0;
	while (i < g_func_count)
	{
		if (token->specs & g_conv_table[i].key)
			return (g_conv_table[i].func(token, args));
		i++;
	}
	return (0);
}

/*
 * 1. Write characters from format sign until null byte or '%' is reached.
 * 2. Turn conversion into token, containing bitflags, width and precision.
 *    ...if that fails, conversion is invalid. Just write the next char.
 * 3. If there's left padding, print it now.
 * 4. Send token and argument list to converter.
 * 5. Converter forwards token and argument list to correct function.
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
		if (get_token(&token, (char **) &format, &n))
			ret += convert(&token, args);
		format++;
	}
	va_end(args);
	return (ret);
}
