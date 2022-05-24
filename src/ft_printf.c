/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/23 13:47:10 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# Prototype of format tags is:
# %[flags][width][.precision][length]specifier

static const char	flags[] = "-+ #0";
static const char	*length[] = {
        "hh",
        "h",
        "l",
        "ll",
        "j",
        "z",
        "t",
        "L"
};
static const char   specifiers[] = "cdieEfgGosuxXpn%";

int	ft_printf(const char *restrict format, ...)
{
	int     n;
    dstr_t

	n = 0;
	while (format[n] != '\0')
	{
		while (format[n] != '%')
			write(1, format + n, 1);
		if (format[n + 1] == '%')
		{
			write(1, format + n, 1);
            n++;
			continue ;
		}
        n++;
	}
	return (n);
}
