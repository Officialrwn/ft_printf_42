/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/21 00:58:47 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_print(t_formats *mod)
{
	char	c;

	c = '0';
	if ((mod->formatcombo & DASH) != 0)
		return ;
	if (mod->uint_flag[2] == PRECISION)
		c = ' ';
	while (mod->width-- > 0)
		mod->char_count += write(1, &c, 1);
}

void	hash_print(t_formats *mod)
{
	int	sign;

	sign = (mod->specifier == 'X') + (mod->specifier == 'x');
	if (sign == 0 && mod->specifier != 'o')
		return ;
	mod->char_count += write(1, "0", 1);
	if (mod->specifier != 'o')
		mod->char_count += write(1, &mod->specifier, 1);
	if (mod->uint_flag[1] == ZERO && mod->uint_flag[2] != PRECISION)
		zero_print(mod);
}

void	space_print(t_formats *mod)
{
	if (*mod->num != '-')
		mod->char_count += write(1, " ", 1);
	if (mod->uint_flag[1] == ZERO)
		zero_print(mod);
}

void	dash_print(t_formats *mod)
{
	if ((mod->formatcombo & DASH_HSP) != 0)
		g_flagprint[mod->flag[1]](mod);
}

//if mod->specifier is dif plus_print()
void	plus_print(t_formats *mod)
{
	if (mod->specifier != 'd' && mod->specifier != 'i')
		return ;
	if (*mod->num != '-')
		mod->char_count += write(1, "+", 1);
	if (mod->uint_flag[1] == ZERO)
		zero_print(mod);
}
