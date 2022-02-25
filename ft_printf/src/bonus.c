/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:52:08 by leotran           #+#    #+#             */
/*   Updated: 2022/02/25 15:58:29 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"

//%b

//colors

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

//%n

//%e
