#include <stdio.h>
#include "ft_printf.h"

int main (void)
{
	int p1 = printf("what does this look like? %#15.11x\n", 2387123);
	int p2 = printf("what does this look like? %#15.12x\n", 2387123);
	int p3 = printf("what does this look like? %#15.13x\n", 2387123);
	int p4 = printf("what does this look like? %#15.14x\n", 2387123);
	int p5 = printf("what does this look like? %#15.15x\n", 2387123);
	int fp1 = ft_printf("what does this look like? %#15.11x\n", 2387123);
	int fp2 = ft_printf("what does this look like? %#15.12x\n", 2387123);
	int fp3 = ft_printf("what does this look like? %#15.13x\n", 2387123);
	int fp4 = ft_printf("what does this look like? %#15.14x\n", 2387123);
	int fp5 = ft_printf("what does this look like? %#15.15x\n", 2387123);
	
	printf("results: p1:%3d  p2:%3d  p3:%3d  p4:%3d  p5:%3d\n", p1, p2, p3, p4, p5);
	printf("results:fp1:%3d fp2:%3d fp3:%3d fp4:%3d fp5:%3d\n", fp1, fp2, fp3, fp4, fp5);
	
	
	p1 = printf("what does this look like? %#06.6x\n", 1);
	p2 = printf("what does this look like? %#07.7x\n", 2);
	p3 = printf("what does this look like? %#08.8x\n", 1);
	p4 = printf("what does this look like? %#09.9x\n", 2);
	p5 = printf("what does this look like? %#010.10x\n", 1);
	fp1 = ft_printf("what does this look like? %#06.6x\n", 1);
	fp2 = ft_printf("what does this look like? %#07.7x\n", 2);
	fp3 = ft_printf("what does this look like? %#08.8x\n", 1);
	fp4 = ft_printf("what does this look like? %#09.9x\n", 2);
	fp5 = ft_printf("what does this look like? %#010.10x\n", 1);
	
	printf("results: p1:%3d  p2:%3d  p3:%3d  p4:%3d  p5:%3d\n", p1, p2, p3, p4, p5);
	printf("results:fp1:%3d fp2:%3d fp3:%3d fp4:%3d fp5:%3d\n", fp1, fp2, fp3, fp4, fp5);


	p1 = printf("what does this look like? %#6x\n", 1);
	p2 = printf("what does this look like? %#7x\n", 2);
	p3 = printf("what does this look like? %#8x\n", 1);
	p4 = printf("what does this look like? %#9x\n", 2);
	p5 = printf("what does this look like? %#10x\n", 1);
	fp1 = ft_printf("what does this look like? %#6x\n", 1);
	fp2 = ft_printf("what does this look like? %#7x\n", 2);
	fp3 = ft_printf("what does this look like? %#8x\n", 1);
	fp4 = ft_printf("what does this look like? %#9x\n", 2);
	fp5 = ft_printf("what does this look like? %#10x\n", 1);
	
	printf("results: p1:%3d  p2:%3d  p3:%3d  p4:%3d  p5:%3d\n", p1, p2, p3, p4, p5);
	printf("results:fp1:%3d fp2:%3d fp3:%3d fp4:%3d fp5:%3d\n", fp1, fp2, fp3, fp4, fp5);


	p1 = printf("what does this look like? %#.6x\n", 1);
	p2 = printf("what does this look like? %#.7x\n", 2);
	p3 = printf("what does this look like? %#.8x\n", 1);
	p4 = printf("what does this look like? %#.9x\n", 2);
	p5 = printf("what does this look like? %#.10x\n", 1);	
	fp1 = ft_printf("what does this look like? %#.6x\n", 1);
	fp2 = ft_printf("what does this look like? %#.7x\n", 2);
	fp3 = ft_printf("what does this look like? %#.8x\n", 1);
	fp4 = ft_printf("what does this look like? %#.9x\n", 2);
	fp5 = ft_printf("what does this look like? %#.10x\n", 1);

	printf("results: p1:%3d  p2:%3d  p3:%3d  p4:%3d  p5:%3d\n", p1, p2, p3, p4, p5);
	printf("results:fp1:%3d fp2:%3d fp3:%3d fp4:%3d fp5:%3d\n", fp1, fp2, fp3, fp4, fp5);


	p1 = printf("what does this look like? %#06x\n", 1);
	p2 = printf("what does this look like? %#07x\n", 2);
	p3 = printf("what does this look like? %#08x\n", 1);
	p4 = printf("what does this look like? %#09x\n", 2);
	p5 = printf("what does this look like? %#010x\n", 1);
	fp1 = ft_printf("what does this look like? %#06x\n", 1);
	fp2 = ft_printf("what does this look like? %#07x\n", 2);
	fp3 = ft_printf("what does this look like? %#08x\n", 1);
	fp4 = ft_printf("what does this look like? %#09x\n", 2);
	fp5 = ft_printf("what does this look like? %#010x\n", 1);
	
	printf("results: p1:%3d  p2:%3d  p3:%3d  p4:%3d  p5:%3d\n", p1, p2, p3, p4, p5);
	printf("results:fp1:%3d fp2:%3d fp3:%3d fp4:%3d fp5:%3d\n", fp1, fp2, fp3, fp4, fp5);




	return 0;
}
