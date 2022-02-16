/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/16 15:16:51 by leotran          ###   ########.fr       */
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
		while (mod->width-- - 1 > 0)
			mod->char_count += write(1, " ", 1);
	}
	else
	{
		while (mod->width-- - 1 > 0)
			mod->char_count += write(1, " ", 1);
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
	int		flag;
	char	c;

	flag = 0;
	c = ' ';
	if (mod->uint_flag[0] == ZERO && mod->uint_flag[1] != DASH)
	{
		c = '0';
		while (mod->width-- - 1 > 0)
			mod->char_count += write(1, &c, 1);
	}
	else if ((mod->formatcombo & DASH) != 0)
	{
		mod->char_count += write(1, "%", 1);
		while (mod->width-- - 1 > 0)
			mod->char_count += write(1, &c, 1);
		return ;
	}
	while (mod->width-- - 1 > 0)
		mod->char_count += write(1, &c, 1);
	write(1, "%", 1);
	mod->char_count += 1;
}

void	error_print(t_formats *mod)
{
	mod->char_count += 0;
	return ;
}
