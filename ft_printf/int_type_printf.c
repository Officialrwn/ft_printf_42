/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 18:06:40 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_print(va_list args)
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

int	uint_print(va_list args)
{
	unsigned long long	ullnum;

	ullnum = va_arg(args, unsigned long long);
	ft_put_ullong_nbr(ullnum);
	return (ft_digit_base_count(ullnum, 10));
}
