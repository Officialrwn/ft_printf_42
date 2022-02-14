/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_int_type_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 09:36:37 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_int_printf(va_list args, t_formats *mod)
{
	char	*arr;
	int		flag;
	int		specifier;
	
	g_flagprint[mod->flag[0]](mod, NULL);
	//hash_print(mod, NULL);
	flag = 1 * (mod->specifier == 'X');
	specifier = 16;
	if (mod->specifier == 'o')
		specifier = 8;
	arr = ft_uitoa_base(va_arg(args, long long), specifier, flag);
	mod->char_count += ft_strlen(arr);
	ft_putstr(arr);
	ft_strdel(&arr);
	return (1);
}
