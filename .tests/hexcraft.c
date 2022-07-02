#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int pf;
	int fp;

	printf("justhex\n");
	pf =    printf("%x", 0); printf(" p\n");
	fp = ft_printf("%x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&width\n");
	pf =    printf("%12x", 0); printf(" p\n");
	fp = ft_printf("%12x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec\n");
	pf =    printf("%.12x", 0); printf(" p\n");
	fp = ft_printf("%.12x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec<width\n");
	pf =    printf("%15.12x", 0); printf(" p\n");
	fp = ft_printf("%15.12x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec>width\n");
	pf =    printf("%12.15x", 0); printf(" p\n");
	fp = ft_printf("%12.15x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nALT FLAG\n--------------------\n\n");
	printf("justhex\n");
	pf =    printf("%#x", 0); printf(" p\n");
	fp = ft_printf("%#x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&width\n");
	pf =    printf("%#12x", 0); printf(" p\n");
	fp = ft_printf("%#12x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec\n");
	pf =    printf("%#.12x", 0); printf(" p\n");
	fp = ft_printf("%#.12x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec<width\n");
	pf =    printf("%#15.12x", 0); printf(" p\n");
	fp = ft_printf("%#15.12x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec>width\n");
	pf =    printf("%#12.15x", 0); printf(" p\n");
	fp = ft_printf("%#12.15x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nZERO FLAG\n--------------------\n\n");
	printf("justhex\n");
	pf =    printf("%0x", 0); printf(" p\n");
	fp = ft_printf("%0x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&width\n");
	pf =    printf("%012x", 0); printf(" p\n");
	fp = ft_printf("%012x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec\n");
	pf =    printf("%0.12x", 0); printf(" p\n");
	fp = ft_printf("%0.12x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec<width\n");
	pf =    printf("%015.12x", 0); printf(" p\n");
	fp = ft_printf("%015.12x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec>width\n");
	pf =    printf("%012.15x", 0); printf(" p\n");
	fp = ft_printf("%012.15x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nALT & ZERO FLAG\n--------------------\n\n");
	printf("justhex\n");
	pf =    printf("%#0x", 0); printf(" p\n");
	fp = ft_printf("%#0x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&width\n");
	pf =    printf("%#012x", 0); printf(" p\n");
	fp = ft_printf("%#012x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec\n");
	pf =    printf("%#0.12x", 0); printf(" p\n");
	fp = ft_printf("%#0.12x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec<width\n");
	pf =    printf("%#015.12x", 0); printf(" p\n");
	fp = ft_printf("%#015.12x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec>width\n");
	pf =    printf("%#012.15x", 0); printf(" p\n");
	fp = ft_printf("%#012.15x", 0); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);



	printf("-----------------------\nBIGNUMS!\n--------------------\n\n");
	printf("justhex\n");
	pf =    printf("%x", 123123123); printf(" p\n");
	fp = ft_printf("%x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&width\n");
	pf =    printf("%12x", 123123123); printf(" p\n");
	fp = ft_printf("%12x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec\n");
	pf =    printf("%.12x", 123123123); printf(" p\n");
	fp = ft_printf("%.12x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec<width\n");
	pf =    printf("%15.12x", 123123123); printf(" p\n");
	fp = ft_printf("%15.12x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec>width\n");
	pf =    printf("%12.15x", 123123123); printf(" p\n");
	fp = ft_printf("%12.15x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nALT FLAG\n--------------------\n\n");
	printf("justhex\n");
	pf =    printf("%#x", 123123123); printf(" p\n");
	fp = ft_printf("%#x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&width\n");
	pf =    printf("%#12x", 123123123); printf(" p\n");
	fp = ft_printf("%#12x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec\n");
	pf =    printf("%#.12x", 123123123); printf(" p\n");
	fp = ft_printf("%#.12x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec<width\n");
	pf =    printf("%#15.12x", 123123123); printf(" p\n");
	fp = ft_printf("%#15.12x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec>width\n");
	pf =    printf("%#12.15x", 123123123); printf(" p\n");
	fp = ft_printf("%#12.15x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nZERO FLAG\n--------------------\n\n");
	printf("justhex\n");
	pf =    printf("%0x", 123123123); printf(" p\n");
	fp = ft_printf("%0x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&width\n");
	pf =    printf("%012x", 123123123); printf(" p\n");
	fp = ft_printf("%012x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec\n");
	pf =    printf("%0.12x", 123123123); printf(" p\n");
	fp = ft_printf("%0.12x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec<width\n");
	pf =    printf("%015.12x", 123123123); printf(" p\n");
	fp = ft_printf("%015.12x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec>width\n");
	pf =    printf("%012.15x", 123123123); printf(" p\n");
	fp = ft_printf("%012.15x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("-----------------------\nALT & ZERO FLAG\n--------------------\n\n");
	printf("justhex\n");
	pf =    printf("%#0x", 123123123); printf(" p\n");
	fp = ft_printf("%#0x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&width\n");
	pf =    printf("%#012x", 123123123); printf(" p\n");
	fp = ft_printf("%#012x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec\n");
	pf =    printf("%#0.12x", 123123123); printf(" p\n");
	fp = ft_printf("%#0.12x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec<width\n");
	pf =    printf("%#015.12x", 123123123); printf(" p\n");
	fp = ft_printf("%#015.12x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("hex&prec>width\n");
	pf =    printf("%#012.15x", 123123123); printf(" p\n");
	fp = ft_printf("%#012.15x", 123123123); printf(" f\n");
	printf("pf[%d] fp[%d]\n\n", pf, fp);



	return (0);
}
