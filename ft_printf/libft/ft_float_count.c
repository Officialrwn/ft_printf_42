/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:58:23 by leotran           #+#    #+#             */
/*   Updated: 2022/02/22 01:23:06 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	get_fractionalnum(long double num, int precision)
{
	int	exponent;

	exponent = 6;
	if (precision > 0 && precision <= 19)
		exponent = precision;
	num -= (long long)num;
	while (exponent-- > 0)
		num *= 10;
	return ((long long)num);
}

size_t	ft_float_count(long double num, int precision)
{
	size_t		count;
	long long	frac_num;
	long double	d_num;

	count = (num < 0) + 1;
	d_num = num;
	d_num *= 1 - 2 * (num < 0);
	frac_num = get_fractionalnum(d_num, precision);
	count += ft_int_base_count(frac_num, 10);
	count += ft_int_base_count((long long)d_num, 10);
	return (count);
}
