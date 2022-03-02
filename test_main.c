/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:23:30 by leo               #+#    #+#             */
/*   Updated: 2022/03/02 14:02:01 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf/libft/libft.h"
#include "float.h"

int main(void)
{
	printf("%f\n", DBL_MAX);
	//printf("%f\n", DBL_MAX / 10);
	printf("\n%f\n",( DBL_MAX / 10) * 10);
	
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