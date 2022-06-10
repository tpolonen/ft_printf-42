#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int pf;
	int fp;

	printf("justoct\n");
	pf =    printf("%o", 666); printf(" p\n");
	fp = ft_printf("%o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&width\n");
	pf =    printf("%12o", 666); printf(" p\n");
	fp = ft_printf("%12o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec\n");
	pf =    printf("%.12o", 666); printf(" p\n");
	fp = ft_printf("%.12o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec<width\n");
	pf =    printf("%15.12o", 666); printf(" p\n");
	fp = ft_printf("%15.12o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec>width\n");
	pf =    printf("%12.15o", 666); printf(" p\n");
	fp = ft_printf("%12.15o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nALT FLAG\n--------------------\n\n");
	printf("justoct\n");
	pf =    printf("%#o", 666); printf(" p\n");
	fp = ft_printf("%#o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&width\n");
	pf =    printf("%#12o", 666); printf(" p\n");
	fp = ft_printf("%#12o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec\n");
	pf =    printf("%#.12o", 666); printf(" p\n");
	fp = ft_printf("%#.12o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec<width\n");
	pf =    printf("%#15.12o", 666); printf(" p\n");
	fp = ft_printf("%#15.12o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec>width\n");
	pf =    printf("%#12.15o", 666); printf(" p\n");
	fp = ft_printf("%#12.15o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nZERO FLAG\n--------------------\n\n");
	printf("justoct\n");
	pf =    printf("%0o", 666); printf(" p\n");
	fp = ft_printf("%0o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&width\n");
	pf =    printf("%012o", 666); printf(" p\n");
	fp = ft_printf("%012o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec\n");
	pf =    printf("%0.12o", 666); printf(" p\n");
	fp = ft_printf("%0.12o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec<width\n");
	pf =    printf("%015.12o", 666); printf(" p\n");
	fp = ft_printf("%015.12o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec>width\n");
	pf =    printf("%012.15o", 666); printf(" p\n");
	fp = ft_printf("%012.15o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nALT & ZERO FLAG\n--------------------\n\n");
	printf("justoct\n");
	pf =    printf("%#0o", 666); printf(" p\n");
	fp = ft_printf("%#0o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&width\n");
	pf =    printf("%#012o", 666); printf(" p\n");
	fp = ft_printf("%#012o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec\n");
	pf =    printf("%#0.12o", 666); printf(" p\n");
	fp = ft_printf("%#0.12o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec<width\n");
	pf =    printf("%#015.12o", 666); printf(" p\n");
	fp = ft_printf("%#015.12o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec>width\n");
	pf =    printf("%#012.15o", 666); printf(" p\n");
	fp = ft_printf("%#012.15o", 666); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);



	printf("-----------------------\nBIGNUMS!\n--------------------\n\n");
	printf("justoct\n");
	pf =    printf("%o", 123123123); printf(" p\n");
	fp = ft_printf("%o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&width\n");
	pf =    printf("%12o", 123123123); printf(" p\n");
	fp = ft_printf("%12o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec\n");
	pf =    printf("%.12o", 123123123); printf(" p\n");
	fp = ft_printf("%.12o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec<width\n");
	pf =    printf("%15.12o", 123123123); printf(" p\n");
	fp = ft_printf("%15.12o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec>width\n");
	pf =    printf("%12.15o", 123123123); printf(" p\n");
	fp = ft_printf("%12.15o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nALT FLAG\n--------------------\n\n");
	printf("justoct\n");
	pf =    printf("%#o", 123123123); printf(" p\n");
	fp = ft_printf("%#o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&width\n");
	pf =    printf("%#12o", 123123123); printf(" p\n");
	fp = ft_printf("%#12o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec\n");
	pf =    printf("%#.12o", 123123123); printf(" p\n");
	fp = ft_printf("%#.12o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec<width\n");
	pf =    printf("%#15.12o", 123123123); printf(" p\n");
	fp = ft_printf("%#15.12o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec>width\n");
	pf =    printf("%#12.15o", 123123123); printf(" p\n");
	fp = ft_printf("%#12.15o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nZERO FLAG\n--------------------\n\n");
	printf("justoct\n");
	pf =    printf("%0o", 123123123); printf(" p\n");
	fp = ft_printf("%0o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&width\n");
	pf =    printf("%012o", 123123123); printf(" p\n");
	fp = ft_printf("%012o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec\n");
	pf =    printf("%0.12o", 123123123); printf(" p\n");
	fp = ft_printf("%0.12o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec<width\n");
	pf =    printf("%015.12o", 123123123); printf(" p\n");
	fp = ft_printf("%015.12o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec>width\n");
	pf =    printf("%012.15o", 123123123); printf(" p\n");
	fp = ft_printf("%012.15o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nALT & ZERO FLAG\n--------------------\n\n");
	printf("justoct\n");
	pf =    printf("%#0o", 123123123); printf(" p\n");
	fp = ft_printf("%#0o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&width\n");
	pf =    printf("%#012o", 123123123); printf(" p\n");
	fp = ft_printf("%#012o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec\n");
	pf =    printf("%#0.12o", 123123123); printf(" p\n");
	fp = ft_printf("%#0.12o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec<width\n");
	pf =    printf("%#015.12o", 123123123); printf(" p\n");
	fp = ft_printf("%#015.12o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("oct&prec>width\n");
	pf =    printf("%#012.15o", 123123123); printf(" p\n");
	fp = ft_printf("%#012.15o", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);



	return (0);
}
