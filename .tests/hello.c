/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:28:06 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/13 17:47:56 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int main(void) {
	ssize_t pf =    printf("Hello from stdio!\n");
	ssize_t fp = ft_printf("Hello from libft!\n");

	printf("\nprintf returned %zu", pf);
	printf("\nft_printf returned %zu\n\n", fp);

	pf =    printf("What about some %%?\n");
	fp = ft_printf("Yeah what about %%?\n");

	printf("\nprintf returned %zu", pf);
	printf("\nft_printf returned %zu\n\n", fp);

	pf = printf("  Printf: So here's a very long amount of text, which could cause issues if the dynamic string doesn't expand as expected. It needs to grow several times here and if it doesn't, well there's gonna be some funny stuff happening is alls im saying!\n");
	fp = printf("ftPrintf: So here's a very long amount of text, which could cause issues if the dynamic string doesn't expand as expected. It needs to grow several times here and if it doesn't, well there's gonna be some funny stuff happening is alls im saying!\n");

	printf("\nprintf returned %zu", pf);
	printf("\nft_printf returned %zu\n\n", fp);

	pf =    printf("Let's try couple chars: %c%c%c\n", 'c', 'y', 'a');
	fp = ft_printf("Let's try couple chars: %c%c%c\n", 'c', 'y', 'a');

	printf("\nprintf returned %zu", pf);
	printf("\nft_printf returned %zu\n\n", fp);

	pf =    printf("A string or two? %s %s!\n", "Hello", "there");
	fp = ft_printf("A string or two? %s %s!\n", "Hello", "there");

	printf("\nprintf returned %zu", pf);
	printf("\nft_printf returned %zu\n\n", fp);


	printf("let's play with strings\n\n");

	pf=printf("lc_printf says:\n%.s %.0s %1.1s\n%020.10s\n\n", "12345", "12345", "12345", "1234567890ABCDEFG");
	fp=ft_printf("ft printf says:\n%.s %.0s %1.1s\n%020.10s\n\n", "12345", "12345", "12345", "1234567890ABCDEFG");

	printf("pf[%d]fp[%d]\n",pf, fp);
	return 0;
}
