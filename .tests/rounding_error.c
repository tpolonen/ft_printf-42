#include <stdio.h>
#include "ft_printf.h"
#include <math.h>

double raund(double rd, double e, int i)
{
	while (i-- > 0)
		rd *= e;
	return rd;
}

int main(void)
{
	printf("testing rounding with different funcs\n");
	printf("rounding 5.0 with round(): e = 0.1, i = 3: %f\n", raund(5.0, 0.1, 3));
	printf("multiplying 5.0 by ACTUAL pow(0.1, 3.0): %f\n", 5.0 * pow(0.1, 3.0));
	return 0;
}
