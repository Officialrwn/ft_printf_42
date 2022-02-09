/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_int_type_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 18:06:09 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	oct_print(va_list args)
{
	char	*arr;
	size_t	size;

	arr = ft_itoa_base(va_arg(args, long long), 8, 0);
	size = ft_strlen(arr);
	ft_putstr(arr);
	ft_strdel(&arr);
	return (size);
}

int	hex_print_lower(va_list args)
{
	char	*arr;
	size_t	size;

	arr = ft_itoa_base(va_arg(args, long long), 16, 0);
	size = ft_strlen(arr);
	ft_putstr(arr);
	ft_strdel(&arr);
	return (size);
}

int	hex_print_upper(va_list args)
{
	char	*arr;
	size_t	size;

	arr = ft_itoa_base(va_arg(args, long long), 16, 1);
	size = ft_strlen(arr);
	ft_putstr(arr);
	ft_strdel(&arr);
	return (size);
}