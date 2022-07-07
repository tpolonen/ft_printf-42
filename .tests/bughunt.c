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

int main(void)
{
	//printf("this apparently causes some issues\n");
	//test_numbers();
	//printf("this REALLY causes some issues\n");
	//test_zero();
	
//	bignum();
	mouli1();
	return (0);
}
