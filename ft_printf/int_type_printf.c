/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 15:22:36 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	int_print(va_list args)
{
	int	x;
	int	count;

	x = va_arg(args, int);
	count = 0;
	ft_putnbr(x);
	while (x % 10 > 0)
	{
		x /= 10;
		count++;
	}	
	return (count);
}

int	uint_print(va_list args)
{
	unsigned long long	ullnum;

	ullnum = va_arg(args, unsigned long long);
	ft_put_ullong_nbr(ullnum);
	return (ft_digit_base_count(ullnum, 10));
}
