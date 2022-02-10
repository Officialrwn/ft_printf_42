/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/10 21:31:32 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_print(va_list args, t_formats *modifiers)
{
	int	num;
	int	count;

	num = va_arg(args, int);
	count = ft_digit_base_count(num, 10);
	if (modifiers->flag[0] == PLUS)
		num = *(int *)plus_print(modifiers, &num);
	
	if (modifiers->flag[0] == ZERO)
		zero_print(modifiers, &count);
	
	ft_putnbr(num);
	return (count);
}

int	uint_print(va_list args, t_formats *modifiers)
{
	unsigned long long	ullnum;

	ullnum = va_arg(args, unsigned long long);
	ft_put_ullong_nbr(ullnum);
	return (ft_digit_base_count(ullnum, 10));
}
