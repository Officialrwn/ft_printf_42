/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/12 14:03:33 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_print(va_list args, t_formats *modifiers)
{
	long long	num;
	long long	sign;

	num = va_arg(args, long long);
	sign = 1 - 2 * (num < 0);
	if (modifiers->length == LENGTH_NULL)
		ft_putnbr((int)num);
	else if (modifiers->length == L)
		ft_putnbr((long)num);
	else
		ft_putnbr(num);
	if (sign == -1)
		modifiers->char_count += 1;
	modifiers->char_count += ft_digit_base_count(num * sign, 10);
	return (1);
}

int	uint_print(va_list args, t_formats *modifiers)
{
	unsigned long long	num;

	num = va_arg(args, unsigned long long);
	if (modifiers->length == LENGTH_NULL)
		ft_putnbr((unsigned int)num);
	else if (modifiers->length == L)
		ft_putnbr((unsigned long)num);
	else
		ft_putnbr(num);
	//modifiers->char_count += ft_digit_base_count(num, 10);
	ft_put_ullong_nbr(num);
	return (1);
}
