/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:51:49 by teppo             #+#    #+#             */
/*   Updated: 2022/09/05 19:31:43 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* So we want to convert float of arbitrary size and precision into array of
 * printable chars. Okay. Since we are using floating point numbers,
 * we could utilize the actual floating point?
 *
 * 1. Start with the number.
 * 2. Find out which direction the radix is.
 * 3. If the number is under 1.0, multiply it by ten until it's greater than 1.
 * 4. If the number is over 10.0, multiply it by 0.1 until it's less than 10.
 * 5. Now we know the exponent. Yay. Also we normalized the number, 
 *    which can now be found in *mantissa.
 */

ssize_t	normalize_double(long double num, long double *mantissa)
{
	ssize_t	exponent;

	exponent = 0;
	*mantissa = num;
	if (num == 0.0)
		return (0);
	if (ft_fabsl(num) < 1.0)
	{
		while (ft_fabsl(*mantissa) < 1.0)
		{
			*mantissa *= 10.0;
			exponent--;
		}
	}
	else
	{
		while (ft_fabsl(*mantissa) >= 10.0)
		{
			*mantissa /= 10.0;
			exponent++;
		}
	}
	return (exponent);
}

/* Actual powf is REAL complicated. It has specific edge cases that are
 * really counterintuitive and replicating it while staying within Norme
 * would be a lot of effort with little payoff. So I opted to make this
 * tiny version of it that is used just here in the context of putfloat.
 */

long double	bad_powfl(long double num, int exp)
{
	long double	out;

	if (exp <= 0)
		return (num);
	out = num;
	while (exp-- > 0)
		out *= num;
	return (out);
}

long double	bad_floorfl(long double num)
{
	long double	temp;

	if (num <= (long double)SIZE_MAX)
		return ((long double)(size_t)num);
	temp = num;
	while (temp >= (long double)SIZE_MAX)
		temp -= (long double)SIZE_MAX;
	temp -= (size_t)temp;
	return (num - temp);
}

long double	bad_roundfl(long double *frac, size_t precision)
{
	long double	temp;
	long double	diff;

	temp = *frac * bad_powfl(10, precision - 1);
	diff = bad_floorfl(temp) - temp;
	if (precision == 0 && diff >= 0.5)
		return (1.0);
	if (diff >= 0.5)
	{
		*frac += (5.0 * bad_powfl(0.1, precision));
		if (*frac >= 1.0)
		{
			*frac = 0.0;
			return (1.0);
		}
	}
	return (0.0);
}
