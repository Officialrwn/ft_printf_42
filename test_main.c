/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:23:30 by leo               #+#    #+#             */
/*   Updated: 2022/03/02 20:42:02 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf/libft/libft.h"
#include "float.h"
#include <math.h>
union Udouble {
		double d;
		unsigned long u;
} udouble;

int main(void)
{
	
	//printf("%f\n", DBL_MAX);
	//printf("%f\n", DBL_MAX / 10);
	//printf("\n%f\n",( DBL_MAX / 10) * 10);
	double num = 123456789123456789123456789123456789.2;
	printf("1st num %f\n", num);
	/* printf("mod: %f\n", mod);
	mod = fmod((num) / i, 10);
	printf("mod: %f\n", mod);
	i *= 10;
	mod = fmod(num / i, 10);
	printf("mod: %f\n", mod);  */
	//printf("%.19f\n", num / 100000000000000000);
	num /= 2;
	printf("2nd num  %.19f\n", num);
	num *= 2;
	printf("3rd num %.19f\n", num);
	
	//num -= (long long)num;
//	printf("%.19f\n", num);
	//num *= 100000000000000000;
	//printf("%.19f\n", num);
	
	/* 	long double num;
	long double remainder;
	num = 444565444646.6465424242242;
	// 				  .6465454101562
	//    444565444646.6465454101562500000000000
	//	  1444565444646.6464843750000000000000000
	//num = 46.6465424242242;
	//	  6.6465424242241 999408520314
	//   46.6465424242242008290304511
	remainder = num - (long)num;
	printf("%.5Lf\n", num);
	printf("%.5Lf\n", remainder); */
	return (0);
}
/* Hashkey algo for flags: #0- +
	char *arr = "0# -+";
	int temp;
	int hashkey;
	for (int i = 0; i < 5; i++)
	{
		hashkey = 1;
		temp = (int)arr[i];
		while (temp > 0)
		{
			if (temp % 10 == 0)
				hashkey *= 1;
			else
				hashkey *= temp % 10;
			temp /= 10;
		}
		hashkey /= 3;
		hashkey %= 10;
		if (hashkey > 5)
			hashkey /= 2;
		if (hashkey == 5)
			hashkey /= 5;
		printf("%c: ", arr[i]);
		printf("%d", hashkey);
		printf(" bitnum: %d\n", 1 << hashkey );
	}
	*/