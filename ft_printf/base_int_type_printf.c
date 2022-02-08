/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_int_type_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 15:35:37 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	oct_print(va_list args)
{
	char	*arr;

	arr = ft_itoa_base(va_arg(args, long long), 8, 0);
	ft_putstr(arr);
	return (ft_strlen(arr));
}

int	hex_print_lower(va_list args)
{
	char	*arr;

	arr = ft_itoa_base(va_arg(args, long long), 16, 0);
	ft_putstr(arr);
	return (ft_strlen(arr));
}

int	hex_print_upper(va_list args)
{
	char	*arr;

	arr = ft_itoa_base(va_arg(args, long long), 16, 1);
	ft_putstr(arr);
	return (ft_strlen(arr));
}
