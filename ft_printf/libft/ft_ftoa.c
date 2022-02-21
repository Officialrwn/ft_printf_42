/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2022/02/21 18:45:22 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fract_to_a(long double num, int precision)
{
	int	exponent;
	int	count;

	exponent = 6;
	if (precision > 0 && precision <= 19)
		exponent = precision;
	num -= (long long)num;
	while (exponent-- > 0)
		num *= 10;
	count = ft_int_base_account(num)		
}
char	*ft_ftoa(long double num, int precision)
{
	int		count;
	char	*arr;

	arr = NULL;
	count = ft_float_count(num, precision);
	return (arr);
}
