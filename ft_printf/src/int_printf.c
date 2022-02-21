/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/21 12:59:00 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_print(t_formats *mod)
{
	get_signed_type(mod);
	get_format_lengths(mod);
	if ((mod->formatcombo & HPS_ZD) == 0)
		width_print(mod);
	if (*mod->num == '-' && (mod->flag[0] != PLUS))
		mod->char_count += write(1, "-", 1);
	g_flagprint[mod->flag[0]](mod);
	precision_print(mod);
	custom_putstr(mod);
}

void	uint_print(t_formats *mod)
{
	get_unsigned_type(mod, 10, 0);
	get_format_lengths(mod);
	if ((mod->formatcombo & HPS_ZD) == 0)
		width_print(mod);
	g_flagprint[mod->flag[0]](mod);
	precision_print(mod);
	custom_putstr(mod);
}

void	base_uint_printf(t_formats *mod)
{
	int	base;
	int	flag;

	flag = 1 * (mod->specifier == 'X');
	base = 16 - 8 * (mod->specifier == 'o');
	get_unsigned_type(mod, base, flag);
	get_format_lengths(mod);
	if ((mod->formatcombo & HPS_ZD) == 0 || mod->uint_flag[2] == PRECISION)
		width_print(mod);
	g_flagprint[mod->flag[0]](mod);
	precision_print(mod);
	custom_putstr(mod);
}

void	float_printf(t_formats *mod)
{
	long double	num;

	num = va_arg(mod->args, long double);
	//printf("%f", num);
	mod->char_count += 0;
}