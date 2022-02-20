/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:04:46 by leo               #+#    #+#             */
/*   Updated: 2022/02/21 00:48:49 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret;
	
	ret = printf("-%0-5d-\n", 5);
	printf(" ret: %d\n", ret);
	ret = ft_printf("-%0-5d-\n", 5);
	printf(" ret: %d\n", ret);
	
	/* int a = -2147483648;
	int ret;

	ret = printf("pri: %-10.5dLol\n", 42);
	printf(" ret: %d\n", ret);
	ret = ft_printf("ft_: %-10.5dLol\n", 42);
	printf(" ret: %d\n", ret);

	ret = printf("pri: %-10.5dLol\n", -42);
	printf(" ret: %d\n", ret);
	ret = ft_printf("ft_: %-10.5dLol\n", -42);
	printf(" ret: %d\n", ret);
	
	ret = printf("pri: %-30.25dLol\n", a);
	printf(" ret: %d\n", ret);
	ret = ft_printf("ft_: %-30.25dLol\n", a);
	printf(" ret: %d\n", ret);
	
	ret = printf("pri: %-30.25dLol\n", 2147483647);
	printf(" ret: %d\n", ret);
	ret = ft_printf("ft_: %-30.25dLol\n", 2147483647);
	printf(" ret: %d\n", ret);	 */	
	
/* 	
	int ret;
	ret = printf("-%#8.5x-\n", 42);
	printf(" ret: %d\n", ret);
	ret = ft_printf("-%#8.5x-\n", 42);
	printf(" ret: %d\n", ret); */
	
	/* int	a;
	int	b;
	a = printf("%hhd\n", (signed char)287);
	b = ft_printf("%hhd\n", (signed char)287);
	printf("\nret: %d \n", a);
	printf("ret: %d \n", b); */
/* 	int ret;
	ret = ft_printf("%");
	printf("\nret: %d\n", ret); */
/* 	int ret;
	int a = 0;
	ret = ft_printf("%.0p, %.p", &a, &a);
	printf ("\nret: %d\n", ret);
	ret = printf("%.0p, %.p", &a, &a);
	printf ("\nret: %d\n", ret); */
	
	/*
	** FLOATS!!!!!
	*/

	/* long double num;
	long double remainder;
	long floatnum;
	int exponent = 15;
	long base = 10;
	while (exponent--)
		base *= 10;
	printf("base: %ld\n", base);
	num = 444565444646.6465454101562;
	remainder = num - (long)num;
	floatnum = remainder * base;
	ft_putnbr(num);
	printf("\n");
	ft_putnbr(floatnum);
	printf("\n");
	printf("%.16Lf\n", num);
	 */

	/*
	** FLOATS!!!!!
	*/
/* 
	int ret;
	int count = 76;

	ret = ft_printf("test nr:0 -%%- HEHEH ret: ");
	printf("%d\n", ret);
	ret = printf("test nr:0 -%%- HEHEH ret: ");
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

 	ret = ft_printf("test nr:0 -%5d- HEHEH ret: ", -5);
	printf("%d\n", ret);
	ret = printf("test nr:0 -%5d- HEHEH ret: ", -5);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:1 -%#-8x- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:1 -%#-8x- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:2 -%+4d- HEHEH ret: ", 5);
	printf("%d\n", ret);
	ret = printf("test nr:2 -%+4d- HEHEH ret: ", 5);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:3 -%+-5d- HEHEH ret: ", 5);
	printf("%d\n", ret);
	ret = printf("test nr:3 -%+-5d- HEHEH ret: ", 5);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%-5d- HEHEH ret: ", -5);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-5d- HEHEH ret: ", -5);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
 
 	ret = ft_printf("test nr:4 -%-#5X- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-#5X- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%- 5i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%- 5i- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%08i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%08i- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%#08x- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%#08x- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%+08i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+08i- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -% 08i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -% 08i- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
	
	ret = ft_printf("test nr:4 -% -8i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -% -8i- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
	
	ret = ft_printf("test nr:4 -%+d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+d- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5; 

	ret = ft_printf("test nr:4 -%+d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+d- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
 
	ret = ft_printf("test nr:4 -%#X- HEHEH ret: ", 255255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%#X- HEHEH ret: ", 255255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -% d- HEHEH ret: ", 255255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -% d- HEHEH ret: ", 255255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -% d- HEHEH ret: ", -255255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -% d- HEHEH ret: ", -255255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;	

	ret = ft_printf("test nr:4 -% d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -% d- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;		

	ret = ft_printf("test nr:4 -%8d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%8d- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;		

	ret = ft_printf("test nr:4 -%8d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%8d- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;	

	ret = ft_printf("test nr:4 -%-d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-d- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;	

	ret = ft_printf("test nr:4 -%0d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%0d- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%+005d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+005d- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
	
	ret = ft_printf("test nr:4 -%+005d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+005d- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%d- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%i- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
	
	ret = ft_printf("test nr:4 -%d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%d- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%i- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%i- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%u- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%u- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%o- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%o- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;	

	ret = ft_printf("test nr:4 -%x- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%x- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
			
	ret = ft_printf("test nr:4 -%X- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%X- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;			
	
	ret = ft_printf("test nr:4 -%x- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%x- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%s- HEHEH ret: ", "HelloWorld");
	printf("%d\n", ret);
	ret = printf("test nr:4 -%s- HEHEH ret: ", "HelloWorld");
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;	
	
	ret = ft_printf("test nr:4 -%c- HEHEH ret: ", '@');
	printf("%d\n", ret);
	ret = printf("test nr:4 -%c- HEHEH ret: ", '@');
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	int a = 42; ret = ft_printf("test nr:4 -%p- HEHEH ret: ", &a);
 	printf("%d\n", ret);
	ret = printf("test nr:4 -%p- HEHEH ret: ", &a);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
	
	ret = ft_printf("test nr:4 -%-30p- HEHEH ret: ", &a);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-30p- HEHEH ret: ", &a);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

 	ret = ft_printf("test nr:4 -%-5c- HEHEH ret: ", '@');
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-5c- HEHEH ret: ", '@');
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%30p- HEHEH ret: ", &a);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%30p- HEHEH ret: ", &a);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
	
	ret = ft_printf("test nr:4 -%5c- HEHEH ret: ", '@');
	printf("%d\n", ret);
	ret = printf("test nr:4 -%5c- HEHEH ret: ", '@');
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%5%- HEHEH ret: ");
	printf("%d\n", ret);
	ret = printf("test nr:4 -%5%- HEHEH ret: ");
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
	
	ret = ft_printf("test nr:4 -%-5%- HEHEH ret: ");
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-5%- HEHEH ret: ");
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%05%- HEHEH ret: ");
	printf("%d\n", ret);
	ret = printf("test nr:4 -%05%- HEHEH ret: ");
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%0-5%- HEHEH ret: ");
	printf("%d\n", ret);
	ret = printf("test nr:4 -%0-5%- HEHEH ret: ");
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%-05%- HEHEH ret: ");
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-05%- HEHEH ret: ");
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
 
 	ret = ft_printf("test nr:4 -%8.5d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%8.5d- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

 	ret = ft_printf("test nr:4 -%8.5d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%8.5d- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
	
	ret = ft_printf("test nr:4 -%5.8d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%5.8d- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%5.8d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%5.8d- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

 	ret = ft_printf("test nr:4 -%-8.5d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-8.5d- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

 	ret = ft_printf("test nr:4 -%-8.5d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-8.5d- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%-5.8d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-5.8d- HEHEH ret: ", -255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;

	ret = ft_printf("test nr:4 -%-5.8d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-5.8d- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
	
 	ret = ft_printf("test nr:4 -%+8.5d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+8.5d- HEHEH ret: ", 255);
	printf("%d\ntest row nr: %d\n\n", ret, count); count += 5;
	
	ret = printf("-%#08.5x-\n", 42);
	printf(" ret: %d\n", ret);
	ret = ft_printf("-%#08.5x-\n", 42);
	printf(" ret: %d\n", ret);

	ret = printf("-%-13p-\n", &a);
	printf(" ret: %d\n", ret);
	ret = ft_printf("-%-13p-\n", &a);
	printf(" ret: %d\n", ret);
	
	ret = printf("-%13p-\n", &a);
	printf(" ret: %d\n", ret);
	ret = ft_printf("-%13p-\n", &a);
	printf(" ret: %d\n", ret);
	
	ret = printf("pri: %+10.5dLol\n", 42);
	printf(" ret: %d\n", ret);
	ret = ft_printf("ft_: %+10.5dLol\n", 42);
	printf(" ret: %d\n", ret);
	
	system("leaks a.out"); */
	return (0);
}
