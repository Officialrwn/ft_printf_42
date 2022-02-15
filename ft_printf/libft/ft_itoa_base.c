/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2022/02/15 08:32:41 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert_itoa_base(long long num, int base, char *arr, int flag)
{
	long long	remainder;
	int			i;

	i = ft_int_base_count(num, base);
	remainder = 0;
	if (flag)
		flag = 55;
	else
		flag = 87;
	while (--i >= 0)
	{
		remainder = num % (long long)base;
		if (remainder > 9)
			arr[i] = remainder + (long long)flag;
		else
			arr[i] = remainder + 48;
		num /= base;
	}
	return (arr);
}

char	*ft_itoa_base(long long num, int base, int flag)
{
	char		*arr;
	int			count;

	count = ft_int_base_count(num, base);
	arr = (char *)malloc(sizeof(char) * count + 1);
	if (arr)
	{
		if (num < 0)
			arr[0] = '-';
		arr[count] = '\0';
		arr = convert_itoa_base(num, base, arr, flag);
	}
	return (arr);
}
