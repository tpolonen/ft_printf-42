#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int pf;
	int fp;

	printf("justdec\n");
	pf =    printf("%d", 666); printf(" p\n");
	fp = ft_printf("%d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%12d", 666); printf(" p\n");
	fp = ft_printf("%12d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%.12d", 666); printf(" p\n");
	fp = ft_printf("%.12d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%15.12d", 666); printf(" p\n");
	fp = ft_printf("%15.12d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%12.15d", 666); printf(" p\n");
	fp = ft_printf("%12.15d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nPlUS FLAG\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%+d", 666); printf(" p\n");
	fp = ft_printf("%+d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%+12d", 666); printf(" p\n");
	fp = ft_printf("%+12d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%+.12d", 666); printf(" p\n");
	fp = ft_printf("%+.12d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%+15.12d", 666); printf(" p\n");
	fp = ft_printf("%+15.12d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%+12.15d", 666); printf(" p\n");
	fp = ft_printf("%+12.15d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nZERO FLAG\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%0d", 666); printf(" p\n");
	fp = ft_printf("%0d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%012d", 666); printf(" p\n");
	fp = ft_printf("%012d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%0.12d", 666); printf(" p\n");
	fp = ft_printf("%0.12d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%015.12d", 666); printf(" p\n");
	fp = ft_printf("%015.12d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%012.15d", 666); printf(" p\n");
	fp = ft_printf("%012.15d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nPlUS & ZERO FLAG\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%+0d", 666); printf(" p\n");
	fp = ft_printf("%+0d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%+012d", 666); printf(" p\n");
	fp = ft_printf("%+012d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%+0.12d", 666); printf(" p\n");
	fp = ft_printf("%+0.12d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%+015.12d", 666); printf(" p\n");
	fp = ft_printf("%+015.12d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%+012.15d", 666); printf(" p\n");
	fp = ft_printf("%+012.15d", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);



	printf("-----------------------\nBIGNUMS!\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%d", 123123123); printf(" p\n");
	fp = ft_printf("%d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%12d", 123123123); printf(" p\n");
	fp = ft_printf("%12d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%.12d", 123123123); printf(" p\n");
	fp = ft_printf("%.12d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%15.12d", 123123123); printf(" p\n");
	fp = ft_printf("%15.12d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%12.15d", 123123123); printf(" p\n");
	fp = ft_printf("%12.15d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nPlUS FLAG\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%+d", 123123123); printf(" p\n");
	fp = ft_printf("%+d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%+12d", 123123123); printf(" p\n");
	fp = ft_printf("%+12d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%+.12d", 123123123); printf(" p\n");
	fp = ft_printf("%+.12d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%+15.12d", 123123123); printf(" p\n");
	fp = ft_printf("%+15.12d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%+12.15d", 123123123); printf(" p\n");
	fp = ft_printf("%+12.15d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nZERO FLAG\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%0d", 123123123); printf(" p\n");
	fp = ft_printf("%0d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%012d", 123123123); printf(" p\n");
	fp = ft_printf("%012d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%0.12d", 123123123); printf(" p\n");
	fp = ft_printf("%0.12d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%015.12d", 123123123); printf(" p\n");
	fp = ft_printf("%015.12d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%012.15d", 123123123); printf(" p\n");
	fp = ft_printf("%012.15d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nPlUS & ZERO FLAG\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%+0d", 123123123); printf(" p\n");
	fp = ft_printf("%+0d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%+012d", 123123123); printf(" p\n");
	fp = ft_printf("%+012d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%+0.12d", 123123123); printf(" p\n");
	fp = ft_printf("%+0.12d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%+015.12d", 123123123); printf(" p\n");
	fp = ft_printf("%+015.12d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%+012.15d", 123123123); printf(" p\n");
	fp = ft_printf("%+012.15d", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);


	printf("-----------------------\nNEGNUMS!\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%d", -666); printf(" p\n");
	fp = ft_printf("%d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%12d", -666); printf(" p\n");
	fp = ft_printf("%12d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%.12d", -666); printf(" p\n");
	fp = ft_printf("%.12d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%15.12d", -666); printf(" p\n");
	fp = ft_printf("%15.12d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%12.15d", -666); printf(" p\n");
	fp = ft_printf("%12.15d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nPlUS FLAG\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%+d", -666); printf(" p\n");
	fp = ft_printf("%+d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%+12d", -666); printf(" p\n");
	fp = ft_printf("%+12d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%+.12d", -666); printf(" p\n");
	fp = ft_printf("%+.12d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%+15.12d", -666); printf(" p\n");
	fp = ft_printf("%+15.12d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%+12.15d", -666); printf(" p\n");
	fp = ft_printf("%+12.15d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nZERO FLAG\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%0d", -666); printf(" p\n");
	fp = ft_printf("%0d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%012d", -666); printf(" p\n");
	fp = ft_printf("%012d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%0.12d", -666); printf(" p\n");
	fp = ft_printf("%0.12d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%015.12d", -666); printf(" p\n");
	fp = ft_printf("%015.12d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%012.15d", -666); printf(" p\n");
	fp = ft_printf("%012.15d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nPlUS & ZERO FLAG\n--------------------\n\n");
	printf("justdec\n");
	pf =    printf("%+0d", -666); printf(" p\n");
	fp = ft_printf("%+0d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&width\n");
	pf =    printf("%+012d", -666); printf(" p\n");
	fp = ft_printf("%+012d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec\n");
	pf =    printf("%+0.12d", -666); printf(" p\n");
	fp = ft_printf("%+0.12d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec<width\n");
	pf =    printf("%+015.12d", -666); printf(" p\n");
	fp = ft_printf("%+015.12d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("dec&prec>width\n");
	pf =    printf("%+012.15d", -666); printf(" p\n");
	fp = ft_printf("%+012.15d", -666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);




	return (0);
}
