/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/22 21:24:54 by leo              ###   ########.fr       */
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
	if ((mod->formatcombo & HPS_ZD) == 0 || (mod->precision > 0 && base != 8))
		width_print(mod);
	g_flagprint[mod->flag[0]](mod);
	precision_print(mod);
	custom_putstr(mod);
}

void	float_printf(t_formats *mod)
{
	long double	num;

	num = va_arg(mod->args, long double);
	if (mod->length == L)
		mod->num = ft_ftoa(num, mod->precision, mod->uint_flag[2]);
	else
		mod->num = ft_ftoa((double)num, mod->precision, mod->uint_flag[2]);
	get_float_format_lengths(mod);
	if ((mod->formatcombo & HPS_ZD) == 0)
		width_print(mod);
	if (*mod->num == '-' && (mod->flag[0] != PLUS))
		mod->char_count += write(1, "-", 1);
	g_flagprint[mod->flag[0]](mod);
	custom_putstr(mod);
}
