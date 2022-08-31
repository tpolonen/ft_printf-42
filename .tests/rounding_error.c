#include <stdio.h>
#include "ft_printf.h"
#include <math.h>

int main(void)
{
	printf("this is the number: 3.1415926500\n");
	int fp = ft_printf("%f*\n", 3.1415926500);
	int pf =    printf("%f!\n", 3.1415926500);
	printf("fp*[%d] pf![%d]\n", fp, pf); 
	fp = ft_printf("%.1f*\n", 3.1415926500);
	pf =    printf("%.1f!\n", 3.1415926500);
	printf("fp*[%d] pf![%d]\n", fp, pf); 

	printf("this is the number: -958.125000\n");
	fp = ft_printf("%f*\n", -958.125000);
	pf =    printf("%f!\n", -958.125000);
	printf("fp*[%d] pf![%d]\n", fp, pf); 
	return 0;
}
