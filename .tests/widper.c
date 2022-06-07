#include "../include/ft_printf.h"
#include <stdio.h>

int main(void) {
	ft_printf("what about width? %010ld\n", (long) 9123);	
	ft_printf("what about precision? %0-.10lld\n", (long long) 2342);	
	ft_printf("what about width AND precision? %10.5u\n\n", 1);
	ft_printf("zero padding? %010.5u\n\n", 1);

	ft_printf("strings? %.5s\n", "hello there!");
	
	printf("will this error out? %*.*d\n", 10, 3, 42);

	return(0);
}
