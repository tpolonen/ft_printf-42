#include <stdio.h>
#include"ft_printf.h"

int main(void){
	int pf = printf("How much this actually outputs? %.1000000000d\n", 1);
	int fp = ft_printf("How much this actually outputs? %.1000000000d\n", 1);

	printf("pf[%d]fp[%d]\n", pf, fp);
	return 0;
}

