/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:28:06 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/31 19:14:14 by tpolonen         ###   ########.fr       */
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

	printf("%lu\n", sizeof(int));

	return 0;
}
