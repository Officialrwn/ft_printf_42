/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/10 14:12:57 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_print(va_list args, t_formats *modifiers)
{
	int	num;
	int	count;

	num = va_arg(args, int);
	count = 0;
	ft_putnbr(num);
	while (num > 0)
	{
		num /= 10;
		count++;
	}	
	return (count);
}

int	uint_print(va_list args, t_formats *modifiers)
{
	unsigned long long	ullnum;

	ullnum = va_arg(args, unsigned long long);
	ft_put_ullong_nbr(ullnum);
	return (ft_digit_base_count(ullnum, 10));
}
