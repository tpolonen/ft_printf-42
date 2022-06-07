#include <stdio.h>
#include "ft_printf.h"

int main (void)
{
	int p1 = printf("what does this look like? %#15.11x\n", 2387123);
	int p2 = printf("what does this look like? %#15.12x\n", 2387123);
	int p3 = printf("what does this look like? %#15.13x\n", 2387123);
	int p4 = printf("what does this look like? %#15.14x\n", 2387123);
	int p5 = printf("what does this look like? %#15.15x\n", 2387123);
	
	printf("results:\np1:%3d\np2:%3d\np3:%3d\np4:%3d\np5:%3d\n", p1, p2, p3, p4, p5);

	int fp1 = ft_printf("what does this look like? %#15.11x\n", 2387123);
	int fp2 = ft_printf("what does this look like? %#15.12x\n", 2387123);
	int fp3 = ft_printf("what does this look like? %#15.13x\n", 2387123);
	int fp4 = ft_printf("what does this look like? %#15.14x\n", 2387123);
	int fp5 = ft_printf("what does this look like? %#15.15x\n", 2387123);
	
	printf("results:\nfp1:%3d\nfp2:%3d\nfp3:%3d\nfp4:%3d\nfp5:%3d\n", fp1, fp2, fp3, fp4, fp5);
	
	
	p1 = printf("what does this look like? %#06.6x\n", 1);
	p2 = printf("what does this look like? %#07.7x\n", 2);
	p3 = printf("what does this look like? %#08.8x\n", 1);
	p4 = printf("what does this look like? %#09.9x\n", 2);
	p5 = printf("what does this look like? %#010.10x\n", 1);
	
	printf("results:\np1:%3d\np2:%3d\np3:%3d\np4:%3d\np5:%3d\n", p1, p2, p3, p4, p5);
	
	p1 = printf("what does this look like? %#6x\n", 1);
	p2 = printf("what does this look like? %#7x\n", 2);
	p3 = printf("what does this look like? %#8x\n", 1);
	p4 = printf("what does this look like? %#9x\n", 2);
	p5 = printf("what does this look like? %#10x\n", 1);
	
	printf("results:\np1:%3d\np2:%3d\np3:%3d\np4:%3d\np5:%3d\n", p1, p2, p3, p4, p5);
	
	p1 = printf("what does this look like? %#.6x\n", 1);
	p2 = printf("what does this look like? %#.7x\n", 2);
	p3 = printf("what does this look like? %#.8x\n", 1);
	p4 = printf("what does this look like? %#.9x\n", 2);
	p5 = printf("what does this look like? %#.10x\n", 1);
	
	printf("results:\np1:%3d\np2:%3d\np3:%3d\np4:%3d\np5:%3d\n", p1, p2, p3, p4, p5);

	p1 = printf("what does this look like? %#06x\n", 1);
	p2 = printf("what does this look like? %#07x\n", 2);
	p3 = printf("what does this look like? %#08x\n", 1);
	p4 = printf("what does this look like? %#09x\n", 2);
	p5 = printf("what does this look like? %#010x\n", 1);
	
	printf("results:\np1:%3d\np2:%3d\np3:%3d\np4:%3d\np5:%3d\n", p1, p2, p3, p4, p5);



	return 0;
}
