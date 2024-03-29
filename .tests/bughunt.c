#include <stdio.h>
#include "ft_printf.h"

void	test_numbers(void)
{
	long long	n[] = {LONG_MIN, INT_MIN, SHRT_MIN, CHAR_MIN, -42,
			-1, 0 , 1, CHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX, UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX};

	for (int i = 0; i < 16; i++)
	{
		printf("number is: %lld\n\n", n[i]);
		ft_printf("d conversion:\t%d!\n", n[i]);
		   printf("d conversion:\t%d*\n", n[i]);
		ft_printf("i conversion:\t%i!\n", n[i]);
		   printf("i conversion:\t%i*\n", n[i]);
		ft_printf("o conversion:\t%o!\n", n[i]);
		   printf("o conversion:\t%o*\n", n[i]);
		ft_printf("u conversion:\t%u!\n", n[i]);
		   printf("u conversion:\t%u*\n", n[i]);
		ft_printf("x conversion:\t%x!\n", n[i]);
		   printf("x conversion:\t%x*\n", n[i]);
		ft_printf("X conversion:\t%X!\n", n[i]);
		   printf("X conversion:\t%X*\n", n[i]);
		printf("\n");
	}
}

void	test_zero(void)
{
	ft_printf("@moulitest: %#.x %#.0x$!\n", 0, 0);
   	   printf("@moulitest: %#.x %#.0x$*\n", 0, 0);
	ft_printf("@moulitest: %.x %.0x$!\n", 0, 0);
	   printf("@moulitest: %.x %.0x$*\n", 0, 0);
	ft_printf("@moulitest: %5.x %5.0x$!\n", 0, 0);
	   printf("@moulitest: %5.x %5.0x$*\n", 0, 0);
	ft_printf("@moulitest: %.o %.0o$!\n", 0, 0);
	   printf("@moulitest: %.o %.0o$*\n", 0, 0);
	ft_printf("@moulitest: %5.o %5.0o$!\n", 0, 0);
 	   printf("@moulitest: %5.o %5.0o$*\n", 0, 0);
	ft_printf("@moulitest: %#.o %#.0o$!\n", 0, 0);
	   printf("@moulitest: %#.o %#.0o$*\n", 0, 0);
	ft_printf("%03.2d$!\n", 0);
	   printf("%03.2d$*\n", 0);
	ft_printf("%03.2d$!\n", 1);
	   printf("%03.2d$*\n", 1);
	ft_printf("@moulitest: %.d %.0d$!\n", 0, 0);
	   printf("@moulitest: %.d %.0d$*\n", 0, 0);
	ft_printf("@moulitest: %5.d %5.0d$!\n", 0, 0);
	   printf("@moulitest: %5.d %5.0d$*\n", 0, 0);
}

void	bignum(void)
{
	ft_printf("% 20u$!\n", 4294967295);
   	   printf("% 20u$*\n", 4294967295);
	ft_printf("%+20u$!\n", 4294967295);
	   printf("%+20u$*\n", 4294967295);
}

void	mouli1(void)
{
	ft_printf("%p!\n", 0);
	   printf("%p*\n", 0);

	ft_printf("["); 
	ft_printf("%"); ft_printf("]!\n");
	printf("["); printf("%"); printf("]*\n");
}

void	mouli2(void)
{
	ft_printf("%#o!\n", 0);
	   printf("%#o*\n", 0);
	ft_printf("%#.0x, %#.x!\n", 0, 0);
	   printf("%#.0x, %#.x*\n", 0, 0);
	ft_printf("%.0p, %.p!\n", 0, 0);
	   printf("%.0p, %.p*\n", 0, 0);
	ft_printf("%.p, %.0p!\n", 0, 0);
	   printf("%.p, %.0p*\n", 0, 0);
	ft_printf("{%*3d}!\n", 5, 0);
	   printf("{%*3d}*\n", 5, 0);
	ft_printf("{%.03s}!\n", 0);
	   printf("{%.03s}*\n", 0);
}

void	mouli3(void)
{
	ft_printf("{%05.*d}!\n", -15, 42);
	   printf("{%05.*d}*\n", -15, 42);
}

void	pft(void)
{
	ft_printf("{%010.03s}!\n", 0);
	   printf("{%010.03s}*\n", 0);
}

void	caruy1(void)
{
	ft_printf("%f!\n", 9.9999997);
	   printf("%f*\n", 9.9999997);
	ft_printf("%f!\n", 9.999999);
	   printf("%f*\n", 9.999999);
	ft_printf("%f!\n", 9.9999999);
	   printf("%f*\n", 9.9999999);
	printf("\n");

	ft_printf("%f!\n", 8.9999997);
	   printf("%f*\n", 8.9999997);
	ft_printf("%f!\n", 8.9999999);
	   printf("%f*\n", 8.9999999);
	printf("\n");

	ft_printf("%.2f!\n", 8.9995);
	   printf("%.2f*\n", 8.9995);
	ft_printf("%.2f!\n", 8.997);
	   printf("%.2f*\n", 8.997);
	ft_printf("%.2f!\n", 8.999);
	   printf("%.2f*\n", 8.999);
	printf("\n");

	ft_printf("%.2f!\n", 9.995);
	   printf("%.2f*\n", 9.995);
	ft_printf("%.2f!\n", 9.9995);
	   printf("%.2f*\n", 9.9995);
	ft_printf("%.2f!\n", 9.997);
	   printf("%.2f*\n", 9.997);
	ft_printf("%.2f!\n", 9.999);
	   printf("%.2f*\n", 9.999);

}

void usign(void)
{
	ft_printf("unsigned numbers and them flags:\n\n");

	int fp = ft_printf("% u*\n", 42);
	int pf =    printf("% u!\n", 42);
	printf("fp=%d | pf=%d\n\n", fp, pf);

	fp = ft_printf("%+u*\n", 42);
	pf =    printf("%+u!\n", 42);
	printf("fp=%d | pf=%d\n\n", fp, pf);
}

void intermission(void)
{
	int fp1 = ft_printf("btw what this returns ");
	int fp2 = ft_printf("compared\nto this one?\n");
	printf("1:%d, 2:%d\n\n", fp1, fp2);
	int pf1 = printf("btw what this returns ");
	int pf2 = printf("compared to\nthis one?\n");
	printf("1:%d, 2:%d\n\n", pf1, pf2);
}

void mouli4(void)
{
	int fp = ft_printf("%.0p, %.p", 0, 0); ft_printf("\n");
	int pf =    printf("%.0p, %.p", 0, 0); printf("\n");
	printf("fp=%d, pf=%d\n\n", fp, pf);

	fp = ft_printf("%.p, %.0p", 0, 0); ft_printf("\n");
	pf =    printf("%.p, %.0p", 0, 0); printf("\n");
	printf("fp=%d, pf=%d\n\n", fp, pf);
/*
	fp = ft_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l); ft_printf("\n");
	pf =    printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l); printf("\n");
	printf("fp=%d, pf=%d\n\n", fp, pf);
	*/
}

void expaa(void)
{
	int fp = ft_printf("%f, %f, %f", 1.4242, 14.242, 142.42); ft_printf("\n");
	int pf =    printf("%f, %f, %f", 1.4242, 14.242, 142.42); printf("\n");
	printf("fp=%d, pf=%d\n\n", fp, pf);
}

void mouli5(void)
{
	int fp = ft_printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l); ft_printf("\n");
	int pf =	printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l); printf("\n");
	printf("fp=%d, pf=%d\n\n", fp, pf);

	fp = ft_printf("{%f}{%lf}{%Lf}", -1.4242, -14.242, -142.42l); ft_printf("\n");
	pf =	printf("{%f}{%lf}{%Lf}", -1.4242, -14.242, -142.42l); printf("\n");
	printf("fp=%d, pf=%d\n\n", fp, pf);
}

void backslide(void)
{
	int fp = ft_printf("{%d}{%.d}{%.10d}", 42, 42, -42); ft_printf("\n");
	int pf =	printf("{%d}{%.d}{%.10d}", 42, 42, -42); printf("\n");
	printf("fp=%d, pf=%d\n\n", fp, pf);
}

int main(void)
{
	//printf("this apparently causes some issues\n");
	//test_numbers();
	//printf("this REALLY causes some issues\n");
	//test_zero();
	
//	bignum();
//	mouli1();
//	mouli2();
//	mouli3();
//	pft();
//	caruy1();
//	intermission();
  mouli4();
//	expaa();
//	mouli5();
//	backslide();
	return (0);
}
