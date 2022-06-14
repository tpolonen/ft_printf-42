#include <stdio.h>
#include "ft_printf.h"

int main(void){
	int pf =    printf("let's adjust left side!!! %-10d*\n", 10);
	int fp = ft_printf("let's adjust left side!!! %-10d!\n", 10);
	
	printf("pf[%d] fd[%d]\n\n", pf, fp);

	pf =    printf("with zero flag? %-010d*\n");
	fp = ft_printf("with zero flag? %-010d!\n");

	printf("pf[%d] fd[%d]\n", pf, fp);
	return (0);
}
