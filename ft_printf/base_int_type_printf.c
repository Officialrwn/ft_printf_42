/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_int_type_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 22:50:17 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	base_int_printf(t_formats *mod)
{
	int		flag;
	int		specifier;
	
	flag = 1 * (mod->specifier == 'X');
	specifier = 16;
	if (mod->specifier == 'o')
		specifier = 8;
	mod->num = ft_uitoa_base(va_arg(mod->args, unsigned long long), specifier, flag);
	g_flagprint[mod->flag[0]](mod);
	if (mod->uint_flag[0] != FLAGNULL)
		return ;
	custom_putstr(mod, mod->num);
}
