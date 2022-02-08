/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_type_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 13:44:35 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	str_print(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr(str);
	return (ft_strlen(str));
}

int	memaddr_print(va_list args)
{
	ft_putaddr(va_arg(args, void *));
	return (14);
}
