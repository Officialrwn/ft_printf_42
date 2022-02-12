/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/12 23:39:19 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_print(va_list args, t_formats *modifiers)
{
	long long	num;
	long long	sign;

	num = va_arg(args, long long);
	sign = 1 - 2 * (num < 0);
	plus_print(modifiers, &num);
	if (modifiers->length == LENGTH_NULL)
		ft_putnbr((int)num);
	else if (modifiers->length == L)
		ft_putnbr((long)num);
	else if (modifiers->length == H)
		ft_putnbr((short)num);
	else if (modifiers->length == HH)
		ft_putnbr((signed char)num);
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
	else if (modifiers->length == H)
		ft_put_u_nbr((unsigned short)num);
	else if (modifiers->length == HH)
		ft_put_u_nbr((unsigned char)num);	
	else
		ft_put_u_nbr(num);
	modifiers->char_count += ft_uint_base_count(num, 10);
	return (1);
}
