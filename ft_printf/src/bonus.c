/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:52:08 by leotran           #+#    #+#             */
/*   Updated: 2022/02/26 01:08:30 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	binary_printf(t_formats *mod)
{
	long long	num;

	num = va_arg(mod->args, long long);
	mod->num = ft_itoa_base(num, 2, 0);
	mod->char_count += write(1, mod->num, ft_strlen(mod->num));
}

void	asterisk_flag(t_formats *mod, int flag)
{
	int	num;
	int	sign;

	num = va_arg(mod->args, int);
	sign = 1 - 2 * (num < 0);
	if (sign == -1 && flag == WIDTH)
	{
		if (mod->uint_flag[0] == ZERO)
			mod->uint_flag[0] = DASH;
		else if (mod->uint_flag[1] == ZERO)
			mod->uint_flag[1] = DASH;
	}	
	if (flag == WIDTH)
		mod->width = num * sign;
	else
	{
		mod->precision = num * (sign == 1);
		mod->uint_flag[2] = PRECISION * (sign == 1);
	}
}

void	n_conversion_printf(t_formats *mod)
{
	int	*num;

	num = (int *)va_arg(mod->args, void *);
	*num = mod->char_count;
}
