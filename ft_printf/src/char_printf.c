/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/21 00:48:19 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_print(t_formats *mod)
{
	char	c;

	c = (char)va_arg(mod->args, int);
	while (mod->width -1 > 0 && mod->uint_flag[0] != DASH)
	{
		mod->char_count += write(1, " ", 1);
		mod->width--;
	}
	mod->char_count += write(1, &c, 1);
	while (mod->width-- - 1 > 0)
		mod->char_count += write(1, " ", 1);
}

void	percentage_putchar(t_formats *mod)
{
	if ((mod->formatcombo & HPS_ZD) == 0 && mod->width - 1 > 0)
		width_print(mod);
	if (mod->uint_flag[0] == ZERO)
		zero_print(mod);
	mod->char_count += write(1, "%", 1);
	while (mod->width-- - 1 > 0 && (mod->formatcombo & DASH) != 0)
		mod->char_count += write(1, " ", 1);
}

void	error_print(t_formats *mod)
{
	mod->char_count += 0;
	return ;
}
