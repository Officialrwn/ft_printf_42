/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 23:52:45 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_print(t_formats *mod)
{
	size_t	len;

	if (mod->width <= 0)
		return ;
	len = ft_strlen(mod->num);
	if (mod->num[0] == '-')
	{
		custom_putchar(mod, '-');
		mod->num = &mod->num[1];
	}
	else if (mod->uint_flag[0] == HASH && mod->specifier != 'o')
		len += 2;
	else if ((mod->formatcombo & HSP) != 0)
		len++;
	while (mod->width-- - (int)len)
		custom_putchar(mod, '0');
	custom_putstr(mod, mod->num);
}

void	hash_print(t_formats *mod)
{
	int	flag;

	flag = 0;
	if (mod->uint_flag[0] == HASH && (mod->formatcombo & HPSZD) != 0)
		flag = 1;
	custom_putchar(mod, '0');
	if (mod->specifier != 'o')
		custom_putchar(mod, mod->specifier);
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
	size_t	len;

	if (mod->uint_flag[0] == DASH && (mod->formatcombo & DHS) != 0)
		g_flagprint[mod->flag[1]](mod);
	if (mod->width > 0)
	{
		len = ft_strlen(mod->num);
		if (mod->num[0] == '-')
		{
			custom_putchar(mod, '-');
			mod->num = &mod->num[1];
		}
		else if ((mod->formatcombo & HASH) != 0 && mod->specifier != 'o')
			len += 2;
		else if ((mod->formatcombo & HSP) != 0)
			len++;
		if (mod->uint_flag[1] == DASH && (mod->formatcombo & HSP) != 0)
			custom_putstr(mod, mod->num);
		while (mod->width-- - (int)len)
			custom_putchar(mod, ' ');
	}
	if (mod->uint_flag[0] == DASH && mod->uint_flag[1] == FLAGNULL)
		custom_putstr(mod, mod->num);
}

void	plus_print(t_formats *mod)
{
	int			flag;
	int			j;

	flag = 0;
	j = mod->flag[1];
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
