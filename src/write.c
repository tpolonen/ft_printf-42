/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:18:12 by teppo             #+#    #+#             */
/*   Updated: 2022/09/08 19:28:17 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* This is pretty kludgy attempt at saving lines from other num conversion
 * functions. Probably could be refactored in existing functions somehow.
 * ._.
 */

int	print_prefix(int negative, int is_zero, t_token *token)
{
	if (((token->specs & F_ALT_FORM) && (token->specs & HEXAL)) || \
			(token->specs & PTR))
	{
		if (is_zero && !(token->specs & PTR))
			return (0);
		if (token->specs & ALL_CAPS)
			return ((int)write(1, "0X", 2));
		return ((int)write(1, "0x", 2));
	}
	if (negative)
		return ((int)write(1, "-", 1));
	if (token->specs & F_PRINT_PLUS)
		return ((int)write(1, "+", 1));
	if (token->specs & F_PADDED_POS)
		return ((int)write(1, " ", 1));
	return (0);
}

/* putstr prints the string representation of several conversions
 * that sometimes need to output string instead of what they usually do.
 * If minimum length is more than strings length, fill chars are
 * appended in front.
 */

int	putstr(const char *str, int min_len, char fill_char)
{
	int	len;
	int	ret;

	len = (int)ft_strlen(str);
	ret = 0;
	if (len < min_len)
		ret += ft_putset(min_len - len, fill_char);
	return (ret + (int)write(1, str, (size_t)len));
}

/* putfloat prints the required amount of digits from normalized float.
 * optionally last digit is rounded or trailing zeroes are trimmed.
 * mantissa is adjusted while printing, so this function can be called
 * repeatedly for the same float.
 *
 * Every time the digit we would print is zero, we count it and continue
 * to the next iteration without printing anything.
 *
 * When we eventually hit a non-zero digit AND it's not the last digit
 * AND we are not trimming zeroes, we print all the counted zeroes and then
 * the digit itself.
 *
 * Of course, if we exit the loop without trimming the zeroes, we print
 * all the zeroes that were "buffered" before returning.
 *
 * This form of the function handles only absolute values.
 */

int	putfloat(ssize_t len, long double *mantissa, int trim)
{
	int	ipart;
	int	ret;
	int	ocount;

	ret = 0;
	ocount = 0;
	while (--len >= 0)
	{
		ipart = (int) *mantissa;
		*mantissa = (*mantissa - (long double) ipart) * 10.0;
		if (ipart == 0)
		{
			if (trim && len == 0)
				return (ret);
			ocount++;
			continue ;
		}
		else if (ocount > 0)
			ret += ft_putset(ocount, '0');
		ocount = 0;
		ret += ft_putchar('0' + (char)ipart);
	}
	ret += ft_putset(ocount, '0');
	return (ret);
}

int putfl(long double num, t_token *token, int trim)
{
	int			ret;
	ssize_t		exp;
	long double	ipart;
	long double	frac;

	ipart = bad_floorfl(num);
	printf("ipart is %Lf\n", ipart);
	frac = num - ipart;
	printf("frac is %Lf\n", frac);
	ipart += bad_roundfl(&frac, (size_t)token->precision, num < 0.0);
	ret = 0;
	exp = normalize_double(ipart, &ipart);
	if (exp >= 0)
		ret += putfloat(exp + 1, &ipart, 0);
	if ((token->precision > 0) || (token->specs & F_ALT_FORM))
		ret += write(1, ".", 1);
	frac *= 10.0;
	ret += putfloat(token->precision, &frac, trim);
	return (ret);
}
