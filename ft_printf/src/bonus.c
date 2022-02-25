/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:52:08 by leotran           #+#    #+#             */
/*   Updated: 2022/02/26 00:29:06 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"

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

void	e_lowerc_printf(t_formats *mod, long double lnum, double dnum)
{
	long double	num;
	int			count;

	count = 0;
	num = 0;
	num += lnum + dnum;
	while (num > 1)
	{
		num /= 10;
		count++;
	}
	num *= 10;
	ft_strdel(&mod->num);
	mod->num = ft_ftoa(num, mod->precision, mod->uint_flag[2]);
	mod->char_count += write(1, mod->num, ft_strlen(mod->num));
	printf("\ncount: %d\n", count - 1);


	//while (num > 0)
	/* int	i;

	i = 0;
	while (mod->num[i] != '.')
		i++;
	i += (*mod->num == '0');
	printf("\ni: %d\n", i - 1); //right number
 */	//if *mod->num == 0 then e-01 
	//else e+nn
}
