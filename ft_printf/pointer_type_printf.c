/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_type_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/10 14:13:02 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_print(va_list args, t_formats *modifiers)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr(str);
	return (ft_strlen(str));
}

int	memaddr_print(va_list args, t_formats *modifiers)
{
	ft_putaddr(va_arg(args, void *));
	return (14);
}
