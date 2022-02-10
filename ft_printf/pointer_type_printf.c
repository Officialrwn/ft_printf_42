/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_type_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/10 05:11:29 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_print(va_list args, t_formats *format)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr(str);
	return (ft_strlen(str));
}

int	memaddr_print(va_list args, t_formats *format)
{
	ft_putaddr(va_arg(args, void *));
	return (14);
}
