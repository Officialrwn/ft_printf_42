/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:45:26 by leotran           #+#    #+#             */
/*   Updated: 2022/02/16 15:17:35 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	length_print(t_formats *mod)
{
	long long	num;

	num = va_arg(mod->args, long long);
	mod->num = ft_itoa_base(num, 10, 0);
	g_flagprint[mod->flag[0]](mod);
	if (mod->flag[0] != FLAGNULL)
		return ;
	if (mod->length == L)
		ft_putnbr((long)num);
	else if (mod->length == H)
		ft_putnbr((short)num);
	else if (mod->length == HH)
		ft_putnbr((signed char)num);
	else
		ft_putnbr(num);
	mod->char_count += ft_int_base_count((long long)num, 10);
}

void	ulength_print(t_formats *mod)
{
	unsigned long long	num;

	num = va_arg(mod->args, unsigned long long);
	mod->num = ft_uitoa_base(num, 10, 0);
	g_flagprint[mod->flag[0]](mod);
	if (mod->flag[0] != FLAGNULL)
		return ;
	if (mod->length == L)
		ft_put_u_nbr((unsigned long)num);
	else if (mod->length == H)
		ft_put_u_nbr((unsigned short)num);
	else if (mod->length == HH)
		ft_put_u_nbr((unsigned char)num);
	else
		ft_put_u_nbr((unsigned long long)num);
	mod->char_count += ft_uint_base_count(num, 10);
}

void	width_print(t_formats *mod)
{
	int	len;

	len = get_num_length(mod);
	if (mod->width-- - len <= 0)
		return ;
	while (mod->width-- - len >= 0)
		custom_putchar(mod, ' ');
}
