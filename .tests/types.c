/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:27:25 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/06 17:57:53 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int main(void) {
	int	a;

	a = 1;
	ft_printf("let's try how different types work!\n");
	ft_printf("what's c? [%c]\n", 'c');
	ft_printf("what's s? [%s]\n", "string!");
	ft_printf("what's p? [%p]\n", &a);
	printf("(actually was %p)\n", &a);
	
	ft_printf("\nhopefully that went well. what about these?\n");
	ft_printf("what's d? [%d]\n", -123456);
	ft_printf("what's i? [%i]\n", -1234567);
	ft_printf("what's o? [%o]\n", 9);
	ft_printf("what's u? [%u]\n", 5000000);
	ft_printf("what's x? [%x]\n", 12);
	ft_printf("what's X? [%X]\n", 13);
	printf("what says printf?\n");
	printf("what's x? [%x]\n", 12);
	printf("what's X? [%X]\n", 13);
	ft_printf("what's #x? [%#x]\n", 12);
	ft_printf("what's #X? [%#X]\n", 13);
	printf("what says printf?\n");
	printf("what's #x? [%#x]\n", 12);
	printf("what's #X? [%#X]\n", 13);
	
	ft_printf("\nlast batch, let's GOOOOOOOOOOOOOOOOOO\n");
	ft_printf("what's e? [%e]\n", 1.0);
	ft_printf("what's f? [%f]\n", 1.1);
	ft_printf("what's g? [%g]\n", 1.2);

	ft_printf("\nBONUS MODE\n");
	ft_printf("ld? [%ld] lld? [%lld] hd? [%hd] hhd? [%hhd]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("ld? [%ld] lld? [%lld] hd? [%hd] hhd? [%hhd]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("li? [%li] lli? [%lli] hi? [%hi] hhi? [%hhi]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("li? [%li] lli? [%lli] hi? [%hi] hhi? [%hhi]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("lo? [%lo] llo? [%llo] ho? [%ho] hho? [%hho]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("lo? [%lo] llo? [%llo] ho? [%ho] hho? [%hho]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("lu? [%lu] llu? [%llu] hu? [%hu] hhi? [%hhu]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("lu? [%lu] llu? [%llu] hu? [%hu] hhi? [%hhu]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("lx? [%lx] llx? [%llx] hx? [%hx] hhx? [%hhx]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("lx? [%lx] llx? [%llx] hx? [%hx] hhx? [%hhx]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("lX? [%lX] llX? [%llX] hX? [%hX] hhX? [%hhX]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("lX? [%lX] llX? [%llX] hX? [%hX] hhX? [%hhX]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	
	ft_printf("\nthanks for playing :)\n");

	return 0;
}
