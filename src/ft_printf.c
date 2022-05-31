/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:00 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/31 17:53:04 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

// Prototype of format tags is:
// %[flags][width][.precision][length]specifier

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
static const char   conv[] = "cdieEfgGosuxXpn%";

int	ft_printf(const char *restrict format, ...)
{
	va_list	arg;
	int     n;
    t_dstr	*out;

	n = 0;
	if (ft_dstrnew(&out, 8) == -1)
		return(-1);
	while (format[n] != '\0')
	{
		while (format[n] != '%')
			ft_dstraddc(&out, format[n]);
		if (format[n + 1] == '%')
		{
			write(1, format + n, 1);
            n++;
		}
        n++;
	}
	write(1, out->str, out->len);
	return(ft_dstrclose(&out, NULL));
}
