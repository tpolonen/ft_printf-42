/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:27:25 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/02 16:43:25 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int main(void) {
	ft_printf("let's try how different types work!\n");
	ft_printf("what's c?%c\n", 'c');
	ft_printf("what's s?%s\n", " string!");
	ft_printf("what's p?%p\n", NULL);
	
	ft_printf("\nhopefully that went well. what about these?\n");
	ft_printf("what's d?%d\n", 1);
	ft_printf("what's i?%i\n", 2);
	ft_printf("what's o?%o\n", 3);
	ft_printf("what's u?%u\n", 4);
	ft_printf("what's x?%x\n", 5);
	ft_printf("what's X?%X\n", 6);
	
	ft_printf("\nlast batch, let's GOOOOOOOOOOOOOOOOOO\n");
	ft_printf("what's e?%e\n", 1.0);
	ft_printf("what's f?%f\n", 1.1);
	ft_printf("what's g?%g\n", 1.2);

	ft_printf("\nBONUS MODE\n");
	ft_printf("ld? %ld lld? %lld hd? %hd hhd? %hhd\n", 1, 2, 3, 4); 
	ft_printf("li? %li lli? %lli hi? %hi hhi? %hhi\n", 1, 2, 3, 4); 
	ft_printf("lo? %lo llo? %llo ho? %ho hho? %hho\n", 1, 2, 3, 4); 
	ft_printf("lu? %lu llu? %llu hu? %hu hhi? %hhu\n", 1, 2, 3, 4); 
	ft_printf("lx? %lx llx? %llx hx? %hx hhx? %hhx\n", 1, 2, 3, 4); 
	ft_printf("lX? %lX llX? %llX hX? %hX hhX? %hhX\n", 1, 2, 3, 4); 
	
	ft_printf("\nthanks for playing :)\n");
}
