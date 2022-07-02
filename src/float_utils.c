/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:51:49 by teppo             #+#    #+#             */
/*   Updated: 2022/07/02 20:14:04 by tpolonen         ###   ########.fr       */
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

long double	round_ld(long double mantissa, ssize_t len, int round)
{
	long double	rd;

	if (len <= 0 || !round)
		return (mantissa);
	rd = 5.0L * bad_powf(0.1, (int)len - 1);
	if ((int)((mantissa + rd) * bad_powf(10.0, (int)len - 2)) % 2 == 0)
		mantissa += rd;
	return (mantissa);
}

