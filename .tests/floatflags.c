#include <stdio.h>
#include "ft_printf.h"

int main(void){
	int pf =    printf("%+010f\n", 1.0 / 0.0);	
	int fp = ft_printf("%+010f\n", 1.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("%+010f\n", -1.0 / 0.0);	
	fp = ft_printf("%+010f\n", -1.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("%+010f\n", 0.0 / 0.0);	
	fp = ft_printf("%+010f\n", 0.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("% f\n", 1.0 / 0.0);	
	fp = ft_printf("% f\n", 1.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("% f\n", -1.0 / 0.0);	
	fp = ft_printf("% f\n", -1.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("% f\n", 0.0 / 0.0);	
	fp = ft_printf("% f\n", 0.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("%+010F\n", 1.0 / 0.0);	
	fp = ft_printf("%+010F\n", 1.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("%+010F\n", -1.0 / 0.0);	
	fp = ft_printf("%+010F\n", -1.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("%+010F\n", 0.0 / 0.0);	
	fp = ft_printf("%+010F\n", 0.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("% F\n", 1.0 / 0.0);	
	fp = ft_printf("% F\n", 1.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("% F\n", -1.0 / 0.0);	
	fp = ft_printf("% F\n", -1.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	pf =    printf("% F\n", 0.0 / 0.0);	
	fp = ft_printf("% F\n", 0.0 / 0.0);

	printf("pf=%d, fp=%d\n", pf, fp);

	return 0;
}
