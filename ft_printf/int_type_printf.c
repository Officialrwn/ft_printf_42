/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 09:03:40 by leo              ###   ########.fr       */
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
