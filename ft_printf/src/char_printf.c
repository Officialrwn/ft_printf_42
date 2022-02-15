/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/15 21:36:50 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_print(t_formats *mod)
{
	ft_putchar(va_arg(mod->args, int));
}

void	custom_putchar(t_formats *mod, int c)
{
	mod->char_count += 1;
	ft_putchar(c);
}

void	percentage_putchar(t_formats *mod)
{
	mod->char_count += 1;
	ft_putchar('%');
}

void	error_print(t_formats *mod)
{
	mod->char_count += 0;
	return ;
}
