/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/18 18:49:45 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_print(t_formats *mod)
{
	int		len;
	int		is_negative;

	if (mod->width > 0)
	{
		is_negative = 1 * (*mod->num == '-');
		len = get_num_length(mod);
		len -= is_negative;
		if (is_negative)
			mod->char_count += write(1, "-", 1);
		while (mod->width-- - len)
			custom_putchar(mod, '0');
	}
	check_precision(mod);
	custom_putstr(mod, mod->num);
}

void	hash_print(t_formats *mod)
{
	int	flag;

	flag = 0;
	if (mod->uint_flag[0] == HASH && (mod->formatcombo & HPS_ZD) != 0)
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
	check_precision(mod);
	custom_putstr(mod, mod->num);
}

void	space_print(t_formats *mod)
{
	int	flag;

	flag = 0;
	if (mod->uint_flag[0] == SPACE && (mod->formatcombo & HPS_ZD) != 0)
		flag = 1;
	if (*mod->num != '-')
		custom_putchar(mod, ' ');
	if (mod->uint_flag[0] == SPACE && mod->uint_flag[1] != 0)
	{
		g_flagprint[mod->flag[1]](mod);
		return ;
	}
	check_precision(mod);
	custom_putstr(mod, mod->num);
}

void	dash_print(t_formats *mod)
{
	if (mod->uint_flag[0] == DASH && (mod->formatcombo & DASH_HS) != 0)
		g_flagprint[mod->flag[1]](mod);
	if (mod->width > 0 && mod->uint_flag[1] != FLAGNULL)
	{
		if (mod->uint_flag[1] == DASH && (mod->formatcombo & DASH_HSP) != 0)
			custom_putstr(mod, mod->num);
		width_print(mod);
	}
	if (mod->uint_flag[0] == DASH && mod->uint_flag[1] == FLAGNULL)
	{
		check_precision(mod);
		custom_putstr(mod, mod->num);
		width_print(mod);
	}
}

void	plus_print(t_formats *mod)
{
	int	flag;

	flag = 0;
	if (mod->uint_flag[0] == PLUS && (mod->formatcombo & HPS_ZD) != 0)
		flag = 1;
	if ((mod->formatcombo & HPS_ZD) == 0)
		width_print(mod);
	if (mod->num[0] != '-')
		custom_putchar(mod, '+');
	if (flag == 1 && mod->uint_flag[1] != 0)
	{
		g_flagprint[mod->flag[1]](mod);
		return ;
	}
	check_precision(mod);
	custom_putstr(mod, mod->num);
}
