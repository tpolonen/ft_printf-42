#include <stdio.h>
#include <ft_printf.h>

int main(void)
{
	printf("so this is how it's supposed to work...? %.f %#.f %#.0f %#.15f*\n",
			0.0000000001, 0.0000000001, 0.0000000001, 0.0000000001);
	ft_printf("so this is how it's supposed to work...? %.f %#.f %#.0f %#.15f!\n",
			0.0000000001, 0.0000000001, 0.0000000001, 0.0000000001);
	printf("so this is how it's supposed to work...? %.e %#.e %#.0e %#.15e*\n",
			0.0000000001, 0.0000000001, 0.0000000001, 0.0000000001);
	ft_printf("so this is how it's supposed to work...? %.e %#.e %#.0e %#.15e!\n",
			0.0000000001, 0.0000000001, 0.0000000001, 0.0000000001);

}
