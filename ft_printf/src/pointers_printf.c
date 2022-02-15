/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_type_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 21:45:08 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_print(t_formats *mod)
{
	char	*str;

	str = va_arg(mod->args, char *);
	ft_putstr(str);
}

void	memaddr_print(t_formats *mod)
{
	ft_putaddr(va_arg(mod->args, void *));
}

void	custom_putstr(t_formats *mod, char *str)
{
	size_t	size;

	size = ft_strlen(str);
	mod->char_count += (int)size;
	ft_putstr(str);
}
