#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int pf, fp;
	printf("whats up with funny numbers\n\n");

	pf =    printf("infinity: %f*\n", 1.0 / 0.0);
	fp = ft_printf("infinity: %f!\n", 1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("negativity: %f*\n", -1.0 / 0.0);
	fp = ft_printf("negativity: %f!\n", -1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("not number: %f*\n", 0.0 / 0.0);
	fp = ft_printf("not number: %f!\n", 0.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("same with positive widths\n");

	pf =    printf("infinity: %10f*\n", 1.0 / 0.0);
	fp = ft_printf("infinity: %10f!\n", 1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("negativity: %10f*\n", -1.0 / 0.0);
	fp = ft_printf("negativity: %10f!\n", -1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("not number: %10f*\n", 0.0 / 0.0);
	fp = ft_printf("not number: %10f!\n", 0.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("same with negative widths\n");

	pf =    printf("infinity: %-10f*\n", 1.0 / 0.0);
	fp = ft_printf("infinity: %-10f!\n", 1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("negativity: %-10f*\n", -1.0 / 0.0);
	fp = ft_printf("negativity: %-10f!\n", -1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("not number: %-10f*\n", 0.0 / 0.0);
	fp = ft_printf("not number: %-10f!\n", 0.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);


	printf("ALLCAPS\n\n");

	pf =    printf("infinity: %F*\n", 1.0 / 0.0);
	fp = ft_printf("infinity: %F!\n", 1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("negativity: %F*\n", -1.0 / 0.0);
	fp = ft_printf("negativity: %F!\n", -1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("not number: %F*\n", -0.0 / 0.0);
	fp = ft_printf("not number: %F!\n", -0.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("same with positive widths\n");

	pf =    printf("infinity: %10F*\n", 1.0 / 0.0);
	fp = ft_printf("infinity: %10F!\n", 1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("negativity: %10F*\n", -1.0 / 0.0);
	fp = ft_printf("negativity: %10F!\n", -1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("not number: %10F*\n", -0.0 / 0.0);
	fp = ft_printf("not number: %10F!\n", -0.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("same with negative widths\n");

	pf =    printf("infinity: %-10F*\n", 1.0 / 0.0);
	fp = ft_printf("infinity: %-10F!\n", 1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("negativity: %-10F*\n", -1.0 / 0.0);
	fp = ft_printf("negativity: %-10F!\n", -1.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	pf =    printf("not number: %-10F*\n", -0.0 / 0.0);
	fp = ft_printf("not number: %-10F!\n", -0.0 / 0.0);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	double inf = 1.0 / 0.0;
	double ninf = -1.0 / 0.0;
	double zero = 0.0;
	double nzero = 42.0 / ninf;

	pf =    printf("here's some doubles: %f %f %f %f\n", inf, ninf, zero, nzero);
	fp = ft_printf("here's some doubles: %f %f %f %f\n", inf, ninf, zero, nzero);
	printf("pf[%d] fp[%d]\n\n", pf, fp);

	printf("is this negative zero? %d\n", 42.0 / nzero == ninf);
	printf("is this negative zero? %d\n", 42.0 / zero == ninf);

	return 0;
}
