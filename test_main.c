/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:23:30 by leo               #+#    #+#             */
/*   Updated: 2022/03/03 23:26:31 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf/libft/libft.h"
#include "float.h"
#include <math.h>

double ft_fmod(double x, double y);

int main(void)
{
	
	//printf("%f\n", DBL_MAX);
	//printf("%f\n", DBL_MAX / 10);
	//printf("\n%f\n",( DBL_MAX / 10) * 10);
	//12345678912345678
	//9223372036854775807
	//10000000000000000 // if over this then 0 after .
	// 9999999999999999
	double num = DBL_MAX;
	
	printf("1st num %f\n", num);
	int i = 0;
	double n = 10;
	int count = 0;
	while (num > __LONG_LONG_MAX__)
	{
		num /= 2;
		count++;	
	}
	//while (num < DBL_MAX)
	//	num *= 2;
	
	printf("count: %d num: %f\n", count, num);
	double mod = 19490628022799998160706764775750376621752453715190015053735812914425897381532852204931230131764020518450609832462817336366918339730406188093155974592625306839062555399912946059741579310980107296705599186958436757747371195850789749891492727230937931225655477606208555094163657179983828221952.0;
count = 0;
	while (mod > __LONG_LONG_MAX__)
	{
		mod /= 2;
		count++;
	}	
	printf("count: %d mod: %f\n", count, mod);
		
	//1797693134862315708145274237317043567980705675258449965989
//	int len = (int)strlen(arr);
//	while (len > 0)
//		printf("%c", arr[len--]);

	//8738177180919299881250404026184124858368
	//8638584214816204040521962506764876465233
	
	
	/* num /= 2;
	printf("2nd num  %.19f\n", num);
	num *= 2;
	printf("3rd num %.19f\n", num); */
	
	///SOLUTION?????
	/* 
	count x times num /= 2 so it fits in a long long and then % 10 to get lastdigit.
	then the formula is:
	remainder = 0;
	while (num > 0)
		remainder += lastdigit * (2 ^ count);//example if count is 5 then 2^5 = 32 then just lastdigit * 32; 
		arr[len] = (remainder % 10) + '0';
		remainder \= 10;
		num /= 10;
	
	Theoretical:
	remainder += (num % 10) * (2 ^ count);
	arr[len] =  (remainder % 10) + '0';
	remainder /= 10;
	num /= 10;
	
	How many times to num /= 2? 
	Maybe have long double defined holding max long long.
	
	while (num > maxlonglong)
		num /= 2;
		count++;
	 */
/* 	int count = 0;
	int n = 0;
	while (n < 5)
	{
		num /= 2;
		n++;
	}	
	printf("2nd num:  %f\n", num);
	n = 0;
	while (n < 5)
	{
		num *= 2;
		n++;
	}	 */
	//printf("2nd num: %f\n", num);
	
	
	
		/* printf("mod: %f\n", mod);
	mod = fmod((num) / i, 10);
	printf("mod: %f\n", mod);
	i *= 10;
	mod = fmod(num / i, 10);
	printf("mod: %f\n", mod);  */
	//printf("%.19f\n", num / 100000000000000000);
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