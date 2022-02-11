/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/11 22:53:30 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_print(va_list args, t_formats *modifiers)
{
	long long	num;

	num = va_arg(args, long long);
	modifiers->char_count += ft_digit_base_count(num, 10);
	ft_putnbr(num);
	return (1);
}

int	uint_print(va_list args, t_formats *modifiers)
{
	unsigned long long	num;

	num = va_arg(args, unsigned long long);
	modifiers->char_count += ft_digit_base_count(num, 10);
	ft_put_ullong_nbr(num);
	return (1);
}

int	test_print(va_list args, t_formats *modifiers)
{
	long long			num;
	unsigned long long	unum;

	num = 0;
	unum = 0;
	if (modifiers->specifier == 'u')
	{
		unum = va_arg(args, unsigned long long));
		//charcount
	}	
	else
	{
		ft_putnbr(va_arg(args, long long));
		//charcount
	}
	return (1);	
}