/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:51:49 by teppo             #+#    #+#             */
/*   Updated: 2022/08/31 21:03:29 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* Actual powf is REAL complicated. It has specific edge cases that are
 * really counterintuitive and replicating it while staying within Norme
 * would be a lot of effort with little payoff. So I opted to make this
 * tiny version of it that is used just here in the context of putfloat.
 */

long double	bad_powf(long double num, int exp)
{
	long double	out;

	if (exp <= 0)
		return (num);
	out = num;
	while (exp-- > 0)
		out *= num;
	return (out);
}

long double roundld(long double value, int prec)
{
	ssize_t			ipart;
	ssize_t			frac;
	long double		temp;
	long double		diff;

	ipart = (size_t)value;
	temp = (value - (long double)ipart) * bad_powf(10, prec - 1);
	frac = (unsigned long)temp;
	diff = temp - (long double)frac;
	if (diff >= 0.5)
	{
		frac++;
		if (frac >= bad_powf(10.0, prec - 1))
		{
			frac = 0;
			ipart++;
		}
	}
	else if (!(diff < 0.5) && ((frac == 0) || (frac & 1)))
		frac++;
	if (prec == 0)
	{
		diff = value - (long double)ipart;
		if ((!(diff < 0.5) || (diff > 0.5)) && (ipart & 1))
			ipart++;
	}
	return ((long double)ipart + (long double)(frac / bad_powf(10, prec - 1)));
}
