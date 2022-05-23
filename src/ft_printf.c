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

int	ft_printf(const char *restrict format, ...)
{
	int	n;

	n = 0;
	while (format[n] != '\0')
	{
		while (format[n] != '%')
			write(1, format + n, 1);
		if (format[n - 1] == '%' || format[n + 1] == '%')
		{
			write(1, format + n, 1);
			continue ;
		}
	}
	return (0);
}
