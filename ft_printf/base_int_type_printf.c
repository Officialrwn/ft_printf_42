/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_int_type_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/10 14:12:45 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	oct_print(va_list args, t_formats *modifiers)
{
	char	*arr;
	size_t	size;

	arr = ft_itoa_base(va_arg(args, long long), 8, 0);
	size = ft_strlen(arr);
	ft_putstr(arr);
	ft_strdel(&arr);
	return (size);
}

int	hex_print_lower(va_list args, t_formats *modifiers)
{
	char	*arr;
	size_t	size;

	arr = ft_itoa_base(va_arg(args, long long), 16, 0);
	size = ft_strlen(arr);
	ft_putstr(arr);
	ft_strdel(&arr);
	return (size);
}

int	hex_print_upper(va_list args, t_formats *modifiers)
{
	char	*arr;
	size_t	size;

	arr = ft_itoa_base(va_arg(args, long long), 16, 1);
	size = ft_strlen(arr);
	ft_putstr(arr);
	ft_strdel(&arr);
	return (size);
}
