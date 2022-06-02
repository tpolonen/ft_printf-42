/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:28:06 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/02 15:58:36 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int main(void) {
	ssize_t pf = printf("Hello from stdio!\n");
	ssize_t fp = ft_printf("Hello from libft!\n");

	printf("\nprintf returned %zu", pf);
	printf("\nft_printf returned %zu\n\n", fp);

	pf = printf("What about some %%?\n");
	fp = ft_printf("Yeah what about %%?\n");

	printf("\nprintf returned %zu", pf);
	printf("\nft_printf returned %zu\n", fp);

	pf = printf("  Printf: So here's a very long amount of text, which could cause issues if the dynamic string doesn't expand as expected. It needs to grow several times here and if it doesn't, well there's gonna be some funny stuff happening is alls im saying!\n");
	fp = printf("ftPrintf: So here's a very long amount of text, which could cause issues if the dynamic string doesn't expand as expected. It needs to grow several times here and if it doesn't, well there's gonna be some funny stuff happening is alls im saying!\n");

	printf("\nprintf returned %zu", pf);
	printf("\nft_printf returned %zu\n", fp);

	return 0;
}
