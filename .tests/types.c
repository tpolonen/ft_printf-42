/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:27:25 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/23 18:10:29 by teppo            ###   ########.fr       */
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
	   printf("printf    (%p)\n", &a);
	ft_printf("alt form? [%#p]\n", &a);
	   printf("printf    (%#p)\n", &a);

	ft_printf("what's p? [%p]\n", NULL);
	   printf("printf    (%p)\n", NULL);
	ft_printf("alt form? [%#p]\n", NULL);
	   printf("printf    (%#p)\n", NULL);

	   printf("printf    [%s]\n", NULL);
	ft_printf("what's s? [%s]\n", NULL);

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

	ft_printf("different num appends? [% d], [% d], [%+d], [%+d], [%d], [%d]\n", 1, -1, 42, -42, 50, -50); 
	   printf("different num appends? [% d], [% d], [%+d], [%+d], [%d], [%d]*\n", 1, -1, 42, -42, 50, -50); 
	
	ft_printf("\nlast batch, let's GOOOOOOOOOOOOOOOOOO\n");

	int fp = ft_printf("what's e? [%e]!\n", 0.000012984719824);
	int pf =    printf("what's e? [%e]*\n", 0.000012984719824);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's e? [%e]!\n", 0.000012984799824);
	pf =    printf("what's e? [%e]*\n", 0.000012984799824);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's f? [%f]!\n", 34298.4584534);
	pf =    printf("what's f? [%f]*\n", 34298.4584534);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's g? [%g]!\n", 1.1283198);
	pf =    printf("what's g? [%g]*\n", 1.1283198);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's g? [%g]!\n", 1128319.328);
	pf =    printf("what's g? [%g]*\n", 1128319.328);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's .5e? [%.5e]!\n", 1128319.328);
	pf =    printf("what's .5e? [%.5e]*\n", 1128319.328);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's g? [%.g]!\n", 1128319.328);
	pf =    printf("what's g? [%.g]*\n", 1128319.328);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's g? [%.2g]!\n", 1128319.328);
	pf =    printf("what's g? [%.2g]*\n", 1128319.328);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	pf =    printf("this is apparently hard: e[%e]*\n", 0.011719);
	fp = ft_printf("this is apparently hard: e[%e]!\n", 0.011719);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	pf =    printf("this is apparently hard: f[%.8f]*\n", 0.011719);
	fp = ft_printf("this is apparently hard: f[%.8f]!\n", 0.011719);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	pf =    printf("this is apparently hard: g[%.8g]*\n", 0.011719000000001);
	fp = ft_printf("this is apparently hard: g[%.8g]!\n", 0.011719000000001);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's .12e? [%.12e]!\n", -0.000012984799824);
	pf =    printf("what's .12e? [%.12e]*\n", -0.000012984799824);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's e? [%e]!\n", -34298.4584534);
	pf =    printf("what's e? [%e]*\n", -34298.4584534);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's .8f? [%.8f]!\n", -0.0011283198);
	pf =    printf("what's .8f? [%.8f]*\n", -0.0011283198);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	fp = ft_printf("what's f? [%f]!\n", -1128319.328);
	pf =    printf("what's f? [%f]*\n", -1128319.328);
	printf("fp[%d] pf[%d]\n\n", fp, pf);

	ft_printf("\nBONUS MODE\n");
	ft_printf("ld? [%ld] lld? [%lld] hd? [%hd] hhd? [%hhd]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("ld? [%ld] lld? [%lld] hd? [%hd] hhd? [%hhd]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("ld? [%ld] lld? [%lld] hd? [%hd] hhd? [%hhd]\n", (long) -2147483640, (long long) -9223372036854775800, (short) -3000, (char) -30);
	printf("ld? [%ld] lld? [%lld] hd? [%hd] hhd? [%hhd]*\n", (long) -2147483640, (long long) -9223372036854775800, (short) -3000, (char) -30);
	ft_printf("li? [%li] lli? [%lli] hi? [%hi] hhi? [%hhi]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("li? [%li] lli? [%lli] hi? [%hi] hhi? [%hhi]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("lo? [%lo] llo? [%llo] ho? [%ho] hho? [%hho]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("lo? [%lo] llo? [%llo] ho? [%ho] hho? [%hho]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("lu? [%lu] llu? [%llu] hu? [%hu] hhu? [%hhu]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("lu? [%lu] llu? [%llu] hu? [%hu] hhu? [%hhu]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("lx? [%lx] llx? [%llx] hx? [%hx] hhx? [%hhx]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("lx? [%lx] llx? [%llx] hx? [%hx] hhx? [%hhx]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("lX? [%lX] llX? [%llX] hX? [%hX] hhX? [%hhX]\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	printf("lX? [%lX] llX? [%llX] hX? [%hX] hhX? [%hhX]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);

	ft_printf("#lx? [%#lx] #llx? [%#llx] #hx? [%#hx] #hhx? [%#hhx]\n",  (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	   printf("#lx? [%#lx] #llx? [%#llx] #hx? [%#hx] #hhx? [%#hhx]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	ft_printf("#lX? [%#lX] #llX? [%#llX] #hX? [%#hX] #hhX? [%#hhX]\n",  (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	   printf("#lX? [%#lX] #llX? [%#llX] #hX? [%#hX] #hhX? [%#hhX]*\n", (long) 2147483648, (long long) 9223372036854775807, (short) 40000, (char) 300);
	
	ft_printf("\nthanks for playing :)\n");

	return 0;
}
