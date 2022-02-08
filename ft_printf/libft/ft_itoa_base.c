/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2022/02/08 14:01:53 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert_itoa_base(long long num, int base, char *arr, int flag)
{
	long long	quotient;
	int			remainder;
	int			i;

	i = ft_digit_base_count(num, base);
	quotient = num;
	remainder = 0;
	if (flag)
		flag = 55;
	else
		flag = 87;
	while (i--)
	{
		remainder = quotient % base;
		if (remainder > 9)
			arr[i] = remainder + flag;
		else
			arr[i] = remainder + 48;
		quotient /= base;
	}
	return (arr);
}

char	*ft_itoa_base(long long llnum, int base, int flag)
{
	long long	num;
	int			count;
	char		*arr;

	num = llnum;
	count = ft_digit_base_count(num, base);
	if (llnum < 0)
		num *= -1;
	arr = (char *)malloc(sizeof(char) * count + 1);
	if (arr)
	{
		arr[count] = '\0';
		arr = convert_itoa_base(num, base, arr, flag);
		if (llnum < 0)
			arr[0] = '-';
	}
	return (arr);
}
