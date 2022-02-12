/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_int_type_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/13 00:32:19 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_int_printf(va_list args, t_formats *modifiers)
{
	char	*arr;
	int		flag;
	int		specifier;
	
	g_flagprint[1](modifiers, NULL);
	//hash_print(modifiers, NULL);
	flag = 1 * (modifiers->specifier == 'X');
	specifier = 16;
	if (modifiers->specifier == 'o')
		specifier = 8;
	arr = ft_uitoa_base(va_arg(args, long long), specifier, flag);
	modifiers->char_count += ft_strlen(arr);
	ft_putstr(arr);
	ft_strdel(&arr);
	return (1);
}
