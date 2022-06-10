/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/10 12:22:29 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_conversion(t_token *token, char **seek)
{
	static const char	conv[] = "cdieEfFgGosuxXpn%";
	int	i;

	i = 0;
	while (i < 17)
	{
		if (**seek == conv[17 - i - 1])
		{
			token->specs |= 1 << i;
			break ;
		}
		i++;
	}
//	printf("\nafter conversion:%d", token->specs);
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
//	printf("\nafter length:%d", token->specs);
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
//	printf("\nafter flags:%d", token->specs);
	token->specs <<= 8;
}

static int	get_token(t_token *token, char **start, int *n)
{
	*token = (t_token){0, 0, 0, '\0'};
	if (*(*start)++ != '%')
	{
		write(1, start, (*n)++);
		return (0);
	}
//	printf("\nbefore flags:%d", token->specs);
	get_flag(token, start);
	if (ft_isdigit(**start))
	{
		token->width = (int) ft_strtol(*start, start);
		if (token->specs & F_RIGHT_PADDING)
			token->width = -(ft_abs(token->width));
	}
	if (**start == '.')
	{
		(*start)++;
		token->precision = (int) ft_strtol(*start, start);
	}
	get_length(token, start);
	get_conversion(token, start);
//	printf("\nflags: *%d, -%d, +%d,  %d, #%d, 0%d\n", (token->specs & F_STAR) > 0, (token->specs & F_RIGHT_PADDING) > 0, (token->specs & F_PRINT_PLUS) > 0, (token->specs & F_PADDED_POS) > 0, (token->specs & F_ALT_FORM) > 0, (token->specs & F_PAD_WITH_ZEROES) > 0);
//	if (token->specs & HEXAL) printf("[HEX]!\n");
	if (token->specs & F_PAD_WITH_ZEROES && token->precision <= 0 && !(token->specs & F_RIGHT_PADDING))
	{
//		printf("bonjour :)");
		token->pad_char = '0';
	}
	else
		token->pad_char = ' ';
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
		if (get_token(&token, (char **) &format, &n))
			ret += dispatch(&token, args);
		else
			ret++;
		format++;
	}
	va_end(args);
	return (ret);
}
