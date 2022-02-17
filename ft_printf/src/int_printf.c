/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/17 19:28:55 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_print(t_formats *mod)
{
	int	num;

	if (mod->length == LENGTH_NULL)
	{
		num = va_arg(mod->args, int);
		mod->num = ft_itoa(num);
		//printf("width: %d precision: %d\n", mod->width, mod->precision);
		check_precision(mod, 0, 0);
		if (mod->width > 0 && mod->uint_flag[0] == FLAGNULL)
			width_print(mod);
		g_flagprint[mod->flag[0]](mod);
		if (mod->uint_flag[0] != FLAGNULL)
			return ;
		custom_putstr(mod, mod->num);
	}
	else
		length_print(mod);
}

void	uint_print(t_formats *mod)
{
	unsigned int	num;

	if (mod->length == LENGTH_NULL)
	{
		num = va_arg(mod->args, unsigned int);
		mod->num = ft_uitoa_base(num, 10, 0);
		check_precision(mod, 0, 0);
		g_flagprint[mod->flag[0]](mod);
		if (mod->uint_flag[0] != FLAGNULL)
			return ;
		custom_putstr(mod, mod->num);
	}
	else
		ulength_print(mod);
}

void	base_int_printf(t_formats *mod)
{
	unsigned long long	num;
	int					flag;
	int					base;

	num = va_arg(mod->args, unsigned long long);
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
	custom_putstr(mod, mod->num);
}
