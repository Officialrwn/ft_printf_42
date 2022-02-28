/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2022/02/28 20:59:56 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*  
static int	bankers_rounding(long double num, int precision_flag, int precision)
{
	int	last_digit;
	int	fract_num;
	int	res;
	int sign;

	res = 0;
	sign = 1 - 2 * (num < 0);
	while (precision-- > 0)
	{
		num *= 10;
		num -= (long long)num;
	}	
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
static char	*fract_to_a(long double num, int precision_flag, int precision)
{
	char	*fract_num;
	int		i;

	i = 0;
	if (precision_flag == 0)
		precision = 6;
	fract_num = ft_strnew(precision);
	num += bankers_rounding(num, 1, precision);
	while (precision-- > 0)
	{
		num *= 10;
		fract_num[i++] = (long long)num;
		num -= (long long)num;
	}
	return (fract_num);
}
*/
/* 
char	*strjoin_int_fract(char *int_num, char *fract_num)
{
	char	*res;
	
}
*/

char	*ft_ftoa(long double num, int precision_flag, int precision)
{
	/*
	char	*int_num;
	char	*fract_num;
	char	*res;
	size_t	size;

	if (precision_flag == 1 && precison == 0)
	{
		num += bankers_rounding(num, precision_flag, precision);
		return (ft_itoa_base((long long)num, 10, 0));
	}	
	fract_num = fract_to_a(num, precision_flag, precision)
	int_num = ft_itoa_base((long long)num, 10, 0);
	size = ft_strlen(int_num) + ft_strlen(fract_num) + (precision_flag == 1);
	res = ft_strnew(size);
	if (res)
		res = strjoin_int_fract(int_num, fract_num);
	ft_strdel(&int_num);
	ft_strdel(&fract_num);
	return (res);*/ )
}
