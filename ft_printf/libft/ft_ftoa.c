/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2022/02/28 14:41:43 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*  
static int	bankers_rounding(long double num, int precision, int precision_flag)
{
	int	last_digit;
	int	fract_num;
	int	res;
	int sign;

	res = 0;
	sign = 1 - 2 * (num < 0);
	while (precision-- > 0)
		num *= 10;
	last_digit = (long long)num % 10;
	fract_num = num - (long long)num;
	if (fract_num > 0.5)
		res++;
	else if (fract_num == 0.5)
		res = ((last_digit + sign) % 2 == 0)
	return (res);
}	
*/

/* 
static char	*fract_to_a(long double num, int precision, int precision_flag)
{
	if (precision_flag == 0)
		precision = 6;
	roundup = bankers_rounding(num, precision, 1);
	while (precision-- > 0)
		num *= 10;
	
}
 */


char	*ft_ftoa(long double num, int precision, int precision_flag)
{
	/*
		if (precision > 19)
			precision = 18;
		#intnum
		if (precision == 0 && precision_flag == PRECISION) // .0 or . 
		{
			roundup = bankers_rounding(num - (long long)num), precision, precision_flag);
			num += roundup;
		}	
		else
		{
			num = (long long)num; ft_itoa_base (num, 10, 0);
			#fract_num
			fract_num = fract_to_a(num, precision, precision_flag)
		}
		
	 */
	 return (NULL);
}
