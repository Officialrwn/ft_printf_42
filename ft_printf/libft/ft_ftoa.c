/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2022/03/01 01:03:22 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long long	bankers_rounding(long double num, int precision)
{
	long long	last_digit;
	long double	fract_num;
	long long	res;
	long long	sign;

	res = 0;
	sign = 1 - 2 * (num < 0);
	while (precision-- > 0)
		num *= 10;
	last_digit = (long long)num % 10;
	fract_num = num - (long long)num;
	if (fract_num > 0.5)
	{
		res++;
	}	
	else if (fract_num == 0.5)
	{
		res = ((last_digit + sign) % 2 == 0);
	}
	return (res);
}	


static char	*fract_to_a(long double num, int precision_flag, int precision)
{
	char	*fract_num;
	int		i;

	i = 0;
	if (precision_flag == 0)
		precision = 6;
	fract_num = ft_strnew(precision);
	num = (num * 10) + bankers_rounding(num, precision);
	while (precision-- > 0)
	{
		fract_num[i++] = ((long long)num % 10) + '0';
		num *= 10;
	}
	return (fract_num);
}

static char	*strjoin_int_fract(char *int_num, char *fract_num)
{
	char	*res;
	size_t	size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(int_num) + ft_strlen(fract_num) + 1;
	res = ft_strnew(size);
	if (res)
	{
		while (int_num[j])
			res[i++] = int_num[j++];
		res[i++] = '.';
		j = 0;
		while (fract_num[j])
			res[i++] = fract_num[j++];
	}
	return (res);
}

char	*ft_ftoa(long double num, int precision_flag, int precision)
{
	
	char	*int_num;
	char	*fract_num;
	char	*res;

	if (precision_flag == 1 && precision == 0)
	{
		num += bankers_rounding(num, precision);
		return (ft_itoa_base((long long)num, 10, 0));
	}	
	fract_num = fract_to_a(num, precision_flag, precision);
	int_num = ft_itoa_base((long long)num, 10, 0);
	res = strjoin_int_fract(int_num, fract_num);
	ft_strdel(&int_num);
	ft_strdel(&fract_num);
	return (res);
}
