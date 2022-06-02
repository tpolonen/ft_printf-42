/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:27:25 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/02 14:59:30 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int main(void) {
	ft_printf("let's try how different types work!\n");
	ft_printf("what's c?%c\n", 'c');
	ft_printf("what's s?%s\n", " string!");
	ft_printf("what's p?%p\n", 0);
	
	ft_printf("\nhopefully that went well. what about these?\n");
	ft_printf("what's d?%d\n", 1);
	ft_printf("what's i?%i\n", 2);
	ft_printf("what's o?%o\n", 3);
	ft_printf("what's u?%u\n", 4);
	ft_printf("what's x?%x\n", 5);
	ft_printf("what's X?%X\n", 6);
	
	ft_printf("\nlast batch, let's GOOOOOOOOOOOOOOOOOO\n");
	ft_printf("what's f?%e\n", 0);
	ft_printf("what's f?%f\n", 0);
	ft_printf("what's f?%g\n", 0);
	
	ft_printf("\nthanks for playing :)\n");
}
