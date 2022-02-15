/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/15 21:53:54 by leo              ###   ########.fr       */
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
		if (mod->width > 0 && mod->uint_flag[0] == FLAGNULL)
			width_print(mod);
		g_flagprint[mod->flag[0]](mod);
		if (mod->uint_flag[0] != FLAGNULL)
			return ;
		ft_putnbr(num);
		mod->char_count += ft_int_base_count((long long)num, 10);
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
		g_flagprint[mod->flag[0]](mod);
		if (mod->uint_flag[0] != FLAGNULL)
			return ;
		ft_putnbr(num);
		mod->char_count += ft_uint_base_count((unsigned long long)num, 10);
	}
	else
		ulength_print(mod);
}

void	base_int_printf(t_formats *mod)
{
	unsigned long long	num;
	int					flag;
	int					specifier;

	num = va_arg(mod->args, unsigned long long);
	flag = 1 * (mod->specifier == 'X');
	specifier = 16;
	if (mod->specifier == 'o')
		specifier = 8;
	mod->num = ft_uitoa_base(num, specifier, flag);
	g_flagprint[mod->flag[0]](mod);
	if (mod->uint_flag[0] != FLAGNULL)
		return ;
	custom_putstr(mod, mod->num);
}
