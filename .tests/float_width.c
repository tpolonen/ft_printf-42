#include <stdio.h>
#include "ft_printf.h"

int main(void){
	int pf = printf("%+010f\n", 3.2352353252332);	
	int fp = ft_printf("%+010f\n", 3.2352353252332);

	printf("pf=%d, fp=%d\n", pf, fp);
	return 0;
}
