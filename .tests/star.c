#include <stdio.h>
#include "ft_printf.h"

int main(void){
	int pf =    printf("You are a %*s, a bright %.*s*\n", 10, "star", 4,  "starrats");
	int fp = ft_printf("You are a %*s, a bright %.*s!\n", 10, "star", 4,  "starrats");
	printf("pf[%d] fp[%d]\n", pf, fp);

	pf =    printf("Star in front? %*.4s Star in back? %10.*s*\n", 10, "stara", 4, "starrats");
	fp = ft_printf("Star in front? %*.4s Star in back? %10.*s!\n", 10, "stara", 4, "starrats");
	printf("pf[%d] fp[%d]\n", pf, fp);

	pf =    printf("Star in front? %*.4s*\n", 10, "stara");
	fp = ft_printf("Star in front? %*.4s!\n", 10, "stara");
	printf("pf[%d] fp[%d]\n", pf, fp);

	pf =    printf("Star in back? %10.*s*\n", 4, "starrats");
	fp = ft_printf("Star in back? %10.*s!\n", 4, "starrats");
	printf("pf[%d] fp[%d]\n", pf, fp);

	pf =    printf("Two stars? %*.*s*\n", 10, 4, "stara");
	fp = ft_printf("Two stars? %*.*s!\n", 10, 4, "stara");
	printf("pf[%d] fp[%d]\n", pf, fp);

	pf =    printf("Bad star? %*10.s*\n", 20, "starrats");
	fp = ft_printf("Bad star? %*10.s!\n", 20, "starrats");
	printf("pf[%d] fp[%d]\n", pf, fp);

	return (0);
}
