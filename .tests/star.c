#include <stdio.h>
#include "ft_printf.h"

int main(void){
	int pf = printf("You are a %*s, a bright %.*s\n", 10, 4, "star", "starrats");
	printf("pf[%d]\n", pf);
	return (0);
}
