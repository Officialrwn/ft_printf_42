/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 16:06:33 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_print(t_formats *mod)
{
	int	num;
	int	sign;

	if (mod->length == LENGTH_NULL)
	{
		num = va_arg(mod->args, int);
		sign = 1 - 2 * (num < 0);
		if (sign == -1)
		{
			mod->sign = 0;
			mod->char_count += 1;
		}
		mod->num = &num;
		g_flagprint[mod->flag[0]](mod);
		ft_putnbr(num);
		num *= sign;
		mod->char_count += ft_uint_base_count((unsigned long long)num, 10);
	}
	else
		length_print(mod);
}

void	uint_print(t_formats *mod)
{
	unsigned int	num;

	if (mod->length == LENGTH_NULL) // and dash is not in flags.
	{
		num = va_arg(mod->args, unsigned int);
		mod->num = &num;
		g_flagprint[mod->flag[0]](mod);
		ft_putnbr(num);
		mod->char_count += ft_uint_base_count((unsigned long long)num, 10);
	}
	else
		ulength_print(mod);
}
