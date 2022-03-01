/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2022/03/01 13:44:58 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	bankers_rounding(long double num, char last_digit)
{
	int	rounding_num;
	int	res;

	rounding_num = last_digit - 48;
	res = 0;
	if (num > 0.5)
		res++;
	else if (res == 0.5)
		res = (rounding_num % 2 == 0);
	return (res);
}	


static char	*fract_to_a(long double num, int precision_flag, int precision)
{
	char	*fract_num;
	int		i;
	long double	sign;
	
	i = 0;
	sign = 1.0 - 2.0 * (num < 0);
	num *= sign;
	if (precision_flag == 0)
		precision = 6;
	fract_num = ft_strnew(precision);
	while (precision-- > 0)
	{
		num *= 10;
		fract_num[i++] = ((long long)num % 10) + '0';
		num -= (long long)num;
	}
	fract_num[i - 1] += bankers_rounding(num, fract_num[i - 1]);
	return (fract_num);
}

static char	*strjoin_int_fract(char *int_num, char *fract_num, int sign)
{
	char	*res;
	size_t	size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(int_num) + ft_strlen(fract_num) + 1 + (sign && *int_num == '0');
	res = ft_strnew(size);
	if (res)
	{
		if (sign == 1 && *int_num == '0')
			res[i++] = '-';
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
	size_t	len;

	int_num = ft_itoa_base((long long)num, 10, 0);
	len = ft_strlen(int_num);
	if (precision_flag == 1 && precision == 0)
	{
		int_num[len - 1] += bankers_rounding(num, int_num[len - 1]);
		return (int_num);
	}	
	fract_num = fract_to_a(num, precision_flag, precision);
	res = strjoin_int_fract(int_num, fract_num, (num < 0));
	ft_strdel(&int_num);
	ft_strdel(&fract_num);
	return (res);
}
