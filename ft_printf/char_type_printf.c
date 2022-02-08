/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 18:06:17 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
