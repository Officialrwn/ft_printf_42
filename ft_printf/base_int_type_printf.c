/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_int_type_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/12 16:53:27 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_int_printf(va_list args, t_formats *modifiers)
{
	char	*arr;
	int		flag;
	int		specifier;

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
