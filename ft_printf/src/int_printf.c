/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/18 12:59:33 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_print(t_formats *mod)
{
	get_signed_type(mod);
	check_precision(mod, 0, 0);
	if (mod->width > 0 && mod->uint_flag[0] == FLAGNULL)
		width_print(mod);
	g_flagprint[mod->flag[0]](mod);
	if (mod->uint_flag[0] != FLAGNULL)
		return ;
	custom_putstr(mod, mod->num);
}

void	uint_print(t_formats *mod)
{
	get_unsigned_type(mod, 10, 0);
	check_precision(mod, 0, 0);
	if (mod->width > 0 && mod->uint_flag[0] == FLAGNULL)
		width_print(mod);
	g_flagprint[mod->flag[0]](mod);
	if (mod->uint_flag[0] != FLAGNULL)
		return ;
	custom_putstr(mod, mod->num);
}

void	base_int_printf(t_formats *mod)
{
	int	base;
	int	flag;

	flag = 1 * (mod->specifier == 'X');
	base = 16;
	if (mod->specifier == 'o')
		base = 8;
	get_unsigned_type(mod, base, flag);
	check_precision(mod, 0, 0);
	if (mod->width > 0 && mod->uint_flag[0] == FLAGNULL)
		width_print(mod);
	g_flagprint[mod->flag[0]](mod);
	if (mod->uint_flag[0] != FLAGNULL)
		return ;
	if (mod->width > 0)
		width_print(mod);
	custom_putstr(mod, mod->num);
	/* unsigned int	num;
	int				flag;
	int				base;

	num = va_arg(mod->args, unsigned int);
	flag = 1 * (mod->specifier == 'X');
	base = 16;
	if (mod->specifier == 'o')
		base = 8;
	mod->num = ft_uitoa_base(num, base, flag);
	check_precision(mod, 0, 0);
	g_flagprint[mod->flag[0]](mod);
	if (mod->uint_flag[0] != FLAGNULL)
		return ;
	if (mod->width > 0)
		width_print(mod);
	custom_putstr(mod, mod->num); */
}
