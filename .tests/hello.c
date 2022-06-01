/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:28:06 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/01 17:25:42 by tpolonen         ###   ########.fr       */
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

//	printf("let's see some printf warnings! %d %d", 2);
//	ft_printf("let's see some ft_printf warnings! %d %d", 2);

//	printf("what happens if %k there's just a random percent");

	ft_printf("%-+ #0llfwonder what this does?\n", 1.0);
	return 0;
}
