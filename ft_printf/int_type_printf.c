/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 12:10:54 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_print(va_list args, t_formats *mod)
{
	long long	num;
	long long	sign;
	int			i;

	num = va_arg(args, long long);
	sign = 1 - 2 * ((long long)num < 0);
	i = mod->flag[0];
	mod->num = &sign;
	//g_flagprint[i](mod);
	//if width is > 0 then call dashprint.
	if (mod->length == LL) // and dash is not in flags.
		ft_putnbr(num);
	else
		length_print(mod);
	if (sign == -1)
	{
		mod->char_count += 1;
		num *= sign;
	}
	mod->char_count += ft_uint_base_count((unsigned long long)num, 10);
}

void	uint_print(va_list args, t_formats *mod)
{
	unsigned long long	num;

	num = va_arg(args, unsigned long long);
	if (mod->length == LENGTH_NULL)
		ft_put_u_nbr((unsigned int)num);
	else if (mod->length == L)
		ft_put_u_nbr((unsigned long)num);
	else if (mod->length == H)
		ft_put_u_nbr((unsigned short)num);
	else if (mod->length == HH)
		ft_put_u_nbr((unsigned char)num);	
	else
		ft_put_u_nbr(num);
	mod->char_count += ft_uint_base_count(num, 10);
}
