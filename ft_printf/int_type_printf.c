/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/12 19:51:50 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_int(int num)
{
	ft_putnbr(num);
}

int	int_print(va_list args, t_formats *modifiers)
{
	long long	num;
	long long	sign;

	num = va_arg(args, long long);
	sign = 1 - 2 * (num < 0);
	if (modifiers->length == LENGTH_NULL)
		test_int(num);//ft_putnbr((int)num);
	else if (modifiers->length == L)
		ft_putnbr((long)num);
	else
		ft_putnbr(num);
	if (sign == -1)
		modifiers->char_count += 1;
	modifiers->char_count += ft_uint_base_count(num * sign, 10);
	return (1);
}

int	uint_print(va_list args, t_formats *modifiers)
{
	unsigned long long	num;

	num = va_arg(args, unsigned long long);
	if (modifiers->length == LENGTH_NULL)
		ft_put_u_nbr((unsigned int)num);
	else if (modifiers->length == L)
		ft_put_u_nbr((unsigned long)num);
	else
		ft_put_u_nbr(num);
	modifiers->char_count += ft_uint_base_count(num, 10);
	return (1);
}
