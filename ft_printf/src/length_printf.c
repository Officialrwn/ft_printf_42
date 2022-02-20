/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:45:26 by leotran           #+#    #+#             */
/*   Updated: 2022/02/20 01:40:41 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_signed_type(t_formats *mod)
{
	long long	num;

	num = va_arg(mod->args, long long);
	if (mod->length == H)
		mod->num = ft_itoa((short)num);
	else if (mod->length == HH)
		mod->num = ft_itoa((signed char)num);
	else if (mod->length == L)
		mod->num = ft_itoa_base((long)num, 10, 0);
	else if (mod->length == LL)
		mod->num = ft_itoa_base((long long)num, 10, 0);
	else
		mod->num = ft_itoa((int)num);
}

void	get_unsigned_type(t_formats *mod, int base, int flag)
{
	unsigned long long	num;

	num = va_arg(mod->args, unsigned long long);
	if (mod->length == H)
		mod->num = ft_uitoa_base((unsigned short)num, base, flag);
	else if (mod->length == HH)
		mod->num = ft_uitoa_base((unsigned char)num, base, flag);
	else if (mod->length == L)
		mod->num = ft_uitoa_base((unsigned long)num, base, flag);
	else if (mod->length == LL)
		mod->num = ft_uitoa_base((unsigned long long)num, base, flag);
	else
		mod->num = ft_uitoa_base((unsigned int)num, base, flag);
}

void	width_print(t_formats *mod)
{
	while (mod->width-- > 0)
		mod->char_count += write(1, " ", 1);
}

void	precision_print(t_formats *mod)
{
	while (mod->precision-- > 0)
		mod->char_count += write(1, "0", 1);
}
