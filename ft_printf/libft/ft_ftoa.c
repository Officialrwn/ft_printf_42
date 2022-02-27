/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2022/02/27 11:43:12 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* REMOVE HEADER */
#include <stdio.h>

static char	*correct_float(long double num, int precision)
{
	char	*temp;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (--precision > 0)
	{
		num *= 10;
		if ((long long)num == 0)
			count++;
	}
	temp = ft_strnew(19);
	while (count-- > 0)
		temp[i++] = '0';
	return (temp);
}

static int	bankers_rounding(long double num)
{
	long long	i;
	long double	fractnum;
	long long	sign;
	long long	last_digit;

	sign = 1 - 2 * (num < 0);
	if (num == 0.5)
		return (1);
	last_digit = ((long long)num % 10) + sign;
	last_digit *= sign;
	fractnum = (num - (long long)num) * sign;
	i = (fractnum >= 0.5);
/* 	if (fractnum == 0.5)
		i += (last_digit % 2 == 0); */
	return ((int)i);
}

static char	*fract_to_a(long double num, int precision, int precision_flag)
{
	long double	sign;
	char		*fractnum;
	char		*temp;
	int			exponent;

	sign = 1 - 2 * (num < 0);
	exponent = 6 * (precision_flag == 0);
	if (precision >= 0 && precision <= 19 && precision_flag == 1)
		exponent = precision;
	else if (precision > 19)
		exponent = 19;
	num -= (long long)num;
	num *= sign;
	temp = correct_float(num, precision);
	while (exponent-- > 0)
		num *= 10;
	num += (bankers_rounding(num)) * (precision != 0);
	fractnum = ft_itoa_base((long long)num, 10, 0);
	fractnum = ft_strjoin_update(temp, fractnum);
	return (fractnum);
}

static char	*strjoin_int_fract(char *int_num, char *fract_num, size_t size)
{
	char	*float_num;
	int		i;
	int		j;

	float_num = ft_strnew(size);
	i = 0;
	j = 0;
	if (float_num)
	{
		while (int_num[j])
			float_num[i++] = int_num[j++];
		float_num[i++] = '.';
		j = 0;
		while (fract_num[j])
			float_num[i++] = fract_num[j++];
	}
	ft_strdel(&int_num);
	ft_strdel(&fract_num);
	return (float_num);
}

char	*ft_ftoa(long double num, int precision, int precision_flag)
{
	char		*float_num;
	char		*int_num;
	char		*fract_num;
	long long	roundup;
	size_t		size;

	roundup = 0;
	if (precision == 0 && precision_flag == 1)
		roundup = (bankers_rounding(num)) * (1 - 2 * (num < 0));
	int_num = ft_itoa_base((long long)num + roundup, 10, 0);
	if (precision == 0 && precision_flag == 1)
		return (int_num);
	fract_num = fract_to_a(num, precision, precision_flag);
	size = ft_float_count(num, precision);
	float_num = strjoin_int_fract(int_num, fract_num, size);
	return (float_num);
}
