/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:39:20 by leotran           #+#    #+#             */
/*   Updated: 2022/02/07 20:41:17 by leo              ###   ########.fr       */
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

int	char_print(va_list args)
{
	ft_putchar(va_arg(args, int));
	return (1);
}

int	str_print(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr(str);
	return (ft_strlen(str));
}

int	custom_putchar(char c)
{
	ft_putchar(c);
	return (1);
}
