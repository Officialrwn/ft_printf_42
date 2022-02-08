/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 15:54:46 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	char_print(va_list args)
{
	ft_putchar(va_arg(args, int));
	return (1);
}

int	custom_putchar(char c)
{
	ft_putchar(c);
	return (1);
}

int	percentage_putchar(va_list args)
{
	ft_putchar('%');
	return (1);
}
