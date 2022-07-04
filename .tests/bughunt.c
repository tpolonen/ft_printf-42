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
	ft_printf("@moulitest: %#.x %#.0x$", 0, 0);
	printf("\n");
	ft_printf("@moulitest: %.x %.0x$", 0, 0);
	printf("\n");
	ft_printf("@moulitest: %5.x %5.0x$", 0, 0);
	printf("\n");
	ft_printf("@moulitest: %.o %.0o$", 0, 0);
	printf("\n");
	ft_printf("@moulitest: %5.o %5.0o$", 0, 0);
	printf("\n");
	ft_printf("@moulitest: %#.o %#.0o$", 0, 0);
	printf("\n");
	ft_printf("%03.2d$", 0);
	printf("\n");
	ft_printf("%03.2d$", 1);
	printf("\n");
	ft_printf("@moulitest: %.d %.0d$", 0, 0);
	printf("\n");
	ft_printf("@moulitest: %5.d %5.0d$", 0, 0);
	printf("\n");
}

void	bignum(void)
{
	ft_printf("% u", 4294967295);
	printf("\n");
	ft_printf("%+u", 4294967295);
	printf("\n");
}

int main(void)
{
	//printf("this apparently causes some issues\n");
	//test_numbers();

	printf("this REALLY causes some issues\n");
	test_zero();
	bignum();
	return (0);
}
