/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/15 11:59:13 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_print(t_formats *mod)
{
	int	len;

	if (mod->width <= 0)
		return ;
	len = get_num_length(mod);
	while (mod->width-- - len)
		custom_putchar(mod, '0');
	custom_putstr(mod, mod->num);
}

void	hash_print(t_formats *mod)
{
	int	flag;

	flag = 0;
	if (mod->uint_flag[0] == HASH && (mod->formatcombo & HPSZD) != 0)
		flag = 1;
	if (*mod->num != '0')
	{
		custom_putchar(mod, '0');
		if (mod->specifier != 'o')
			custom_putchar(mod, mod->specifier);
	}
	if (flag == 1 && mod->uint_flag[1] != 0)
	{
		g_flagprint[mod->flag[1]](mod);
		return ;
	}
	custom_putstr(mod, mod->num);
}

void	space_print(t_formats *mod)
{
	int	flag;

	flag = 0;
	if (mod->uint_flag[0] == SPACE && (mod->formatcombo & HPSZD) != 0)
		flag = 1;
	custom_putchar(mod, ' ');
	if (mod->uint_flag[0] == SPACE && mod->uint_flag[1] != 0)
	{
		g_flagprint[mod->flag[1]](mod);
		return ;
	}
	custom_putstr(mod, mod->num);
}

void	dash_print(t_formats *mod)
{
	if (mod->uint_flag[0] == DASH && (mod->formatcombo & DHS) != 0)
		g_flagprint[mod->flag[1]](mod);
	if (mod->width > 0 && mod->uint_flag[1] != FLAGNULL)
	{
		if (mod->uint_flag[1] == DASH && (mod->formatcombo & HSP) != 0)
			custom_putstr(mod, mod->num);
		width_print(mod);
	}
	if (mod->uint_flag[0] == DASH && mod->uint_flag[1] == FLAGNULL)
	{
		custom_putstr(mod, mod->num);
		width_print(mod);
	}
}

void	plus_print(t_formats *mod)
{
	int	flag;

	flag = 0;
	if (mod->uint_flag[0] == PLUS && (mod->formatcombo & HPSZD) != 0)
		flag = 1;
	if (mod->num[0] != '-')
		custom_putchar(mod, '+');
	if (flag == 1 && mod->uint_flag[1] != 0)
	{
		g_flagprint[mod->flag[1]](mod);
		return ;
	}
	custom_putstr(mod, mod->num);
}
