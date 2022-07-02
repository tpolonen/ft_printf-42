/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/07/02 20:02:21 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
			if (token->specs & PTR)
				token->specs |= F_ALT_FORM;
			if (token->specs & INTEGER)
				if (token->specs & F_RIGHT_PADDING || token->width < 0)
					token->pchar = ' ';
			if ((token->specs & FLOAT) && (token->specs & F_RIGHT_PADDING))
				token->pchar = ' ';
			return (0);
		}
		i--;
	}
	return (1);
}

static void	get_length(t_token *token, char **seek)
{
	int			i;
	size_t		len;
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
	const char	flags[] = "-+ #0";

	while (**seek != '\0')
	{
		i = 4;
		stop = 1;
		while (i >= 0)
		{
			if (**seek == flags[i])
			{
				token->specs |= 1 << (4 - i);
				if (flags[i] == '0')
					token->pchar = '0';
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

/*
 * This function converts the specifiers into usable form.
 * The flags, length and conversion are recorded into bitflag,
 * optional width and precision are saved as integers.
 * Width is by default 0, precision is -1 since precision 0
 * has a specific meaning.
 *
 * Some hard checks are made after bitflag is converted
 * into it's final form: 
 * - If any amount of precision or left adjustment is 
 *   specified, zero flag is invalid.
 * - If left adjustment flag is set, width is converted
 *   to negative.
 * - If conversion is a pointer, alternate form flag
 *   will be set.
 */

static int	get_token(t_token *token, char **start, va_list args)
{
	if (*(++(*start)) == '\0')
		return (-1);
	*token = (t_token){0, 0, -1, ' '};
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
	if (**start == '*')
	{
		token->precision = (int) va_arg(args, int);
		(*start)++;
	}
	get_length(token, start);
	if (get_conversion(token, start))
		return (1);
	if (token->specs & F_RIGHT_PADDING)
		token->width = -(ft_abs(token->width));
	return (0);
}

/*
 * 1. Write characters from format sign until null byte or '%' is reached.
 * 2. Turn specifiers into token, containing bitflags, width and precision.
 *    ...if that fails, conversion is invalid. Just write the last char.
 * 3. Send token and argument list to dispatcher.
 * 4. Dispatcher forwards token and argument list to correct function.
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
		format += write(1, format, (size_t)n);
		if (*format == '\0')
			break ;
		if (get_token(&token, (char **) &format, args) == 0)
			ret += dispatch(&token, args);
		else
			ret += (int)write(1, format, 1);
		format++;
	}
	va_end(args);
	return (ret);
}
