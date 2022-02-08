/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2022/02/08 03:15:29 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	icount(long long llnum, int base)
{
	int			count;
	long long	n;

	count = 0;
	n = llnum;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

static char	*convert_itoa_base(long long num, int base, char *arr, int count)
{
	long long	quotient;
	int			remainder;

	quotient = num;
	remainder = 0;
	while (count--)
	{
		remainder = quotient % base;
		if (base == 16)
			arr[count] = HEX[remainder];
		else
			arr[count] = remainder + '0';
		quotient /= base;
	}
	return (arr);
}

char	*ft_itoa_base(long long llnum, int base)
{
	long long	num;
	int			count;
	char		*arr;

	num = llnum;
	count = icount(num, base);
	if (llnum < 0)
		num *= -1;
	arr = (char *)malloc(sizeof(char) * count + 1);
	if (arr)
	{
		arr[count] = '\0';
		arr = convert_itoa_base(num, base, arr, count);
		if (llnum < 0)
			arr[0] = '-';
	}
	return (arr);
}
