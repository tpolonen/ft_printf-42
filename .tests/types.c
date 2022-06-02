/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:27:25 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/02 12:32:37 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int main(void) {
	ft_printf("let's try how different types work!\n");
	ft_printf("what's c?%c\n", 0);
	ft_printf("what's s?%s\n", 0);
	ft_printf("what's p?%p\n", 0);
	
	ft_printf("\nhopefully that went well. what about these?\n");
	ft_printf("what's d?%d\n", 0);
	ft_printf("what's i?%i\n", 0);
	ft_printf("what's o?%o\n", 0);
	ft_printf("what's u?%u\n", 0);
	ft_printf("what's x?%x\n", 0);
	ft_printf("what's X?%X\n", 0);
	
	ft_printf("\nlast batch, let's GOOOOOOOOOOOOOOOOOO\n");
	ft_printf("what's f?%f\n", 0);
	
	ft_printf("\nthanks for playing :)\n");
}
