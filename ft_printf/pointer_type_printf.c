/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_type_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 11:52:41 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_print(va_list args, t_formats *mod)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr(str);
}

void	memaddr_print(va_list args, t_formats *mod)
{
	ft_putaddr(va_arg(args, void *));
}
