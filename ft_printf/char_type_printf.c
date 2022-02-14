/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 15:21:07 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_print(t_formats *mod)
{
	ft_putchar(va_arg(mod->args, int));
}

int	custom_putchar(int c)
{
	ft_putchar(c);
	return (1);
}

void	percentage_putchar(t_formats *mod)
{
	ft_putchar('%');
}

void	error_print(t_formats *mod)
{
	return ;
}

