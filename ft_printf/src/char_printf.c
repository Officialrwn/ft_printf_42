/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/16 14:04:58 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_print(t_formats *mod)
{
 	char	c;

	c = (char)va_arg(mod->args, int);
	if (mod->uint_flag[0] == DASH)
	{
		ft_putchar(c);
		//width_print(mod);
	}
	else
	{
		if (mod->width > 0)
		//	width_print(mod);
		ft_putchar(c);
	}
	mod->char_count += 1;
}

void	custom_putchar(t_formats *mod, int c)
{
	mod->char_count += 1;
	ft_putchar(c);
}

void	percentage_putchar(t_formats *mod)
{
	mod->char_count += 1;
	ft_putchar('%');
}

void	error_print(t_formats *mod)
{
	mod->char_count += 0;
	return ;
}
