#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int pf =    printf("here's a bad flag: % 0k\n", 6);
	int fp = ft_printf("here's a bad flag: % 0k\n", 6);

	printf("pf[%d] fp[%d]\n", pf, fp);
	return (0);
}
