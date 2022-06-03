#include "../include/ft_printf.h"
#include <stdio.h>

int main(void) {
	ft_printf("what about width? %-2ld\n", 2);	
	ft_printf("what about precision? %-.2lld\n", 2);	
	ft_printf("what about width AND precision? %-2.2u\n", 2);	
	return(0);
}
