/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:28:06 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/19 16:49:47 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int main(void) {
	int pf =    printf("Hello from stdio!\n");
	int fp = ft_printf("Hello from libft!\n");

	printf("\nprintf returned %d", pf);
	printf("\nft_printf returned %d\n\n", fp);

	pf =    printf("What about some %%?\n");
	fp = ft_printf("Yeah what about %%?\n");

	printf("\nprintf returned %d", pf);
	printf("\nft_printf returned %d\n\n", fp);

	pf = printf("  Printf: So here's a very long amount of text, which could cause issues if the dynamic string doesn't expand as expected. It needs to grow several times here and if it doesn't, well there's gonna be some funny stuff happening is alls im saying!\n");
	fp = printf("ftPrintf: So here's a very long amount of text, which could cause issues if the dynamic string doesn't expand as expected. It needs to grow several times here and if it doesn't, well there's gonna be some funny stuff happening is alls im saying!\n");

	printf("\nprintf returned %d", pf);
	printf("\nft_printf returned %d\n\n", fp);

	pf =    printf("Let's try couple chars: %c%c%c\n", 'c', 'y', 'a');
	fp = ft_printf("Let's try couple chars: %c%c%c\n", 'c', 'y', 'a');

	printf("\nprintf returned %d", pf);
	printf("\nft_printf returned %d\n\n", fp);

	pf =    printf("A string or two? %s %s!\n", "Hello", "there");
	fp = ft_printf("A string or two? %s %s!\n", "Hello", "there");

	printf("\nprintf returned %d", pf);
	printf("\nft_printf returned %d\n\n", fp);


	printf("let's play with strings\n\n");

	pf=   printf("lc_printf says:\n%.s %.0s %1.1s\n%020.10s\n\n", 
			"12345", "12345", "12345", "1234567890ABCDEFG");
	fp=ft_printf("ft printf says:\n%.s %.0s %1.1s\n%020.10s\n\n", 
			"12345", "12345", "12345", "1234567890ABCDEFG");

	printf("pf[%d]fp[%d]\n",pf, fp);

	printf("...can we actually print just a zero\n%i %d %u %o %x\n",0, 0, 0, 0, 0);
	return 0;
}
