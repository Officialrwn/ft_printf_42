/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:44:08 by leotran           #+#    #+#             */
/*   Updated: 2022/02/14 16:11:24 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_formatcombo(t_formats *mod)
{
	u_int16_t	flag0;
	u_int16_t	flag1;

	flag0 = mod->uint_flag[0];
	flag1 = mod->uint_flag[1];
	mod->formatcombo = flag0 | flag1;
	return (0);
}

void	initialize_t_formats(t_formats *mod)
{
	int	i;

	i = 3;
	while (i--)
		mod->uint_flag[i] = FLAGNULL;
	mod->length = LENGTH_NULL;
	mod->tempformat = NULL;
	mod->width = 0;
	mod->precision = 0;
	mod->specifier = 0;
	mod->flag[0] = 0;
	mod->flag[1] = 0;
	mod->char_count = 0;
	mod->formatcombo = 0;
	mod->num = NULL;
	mod->sign = 1;
	mod->int_length = 0;
}

void	length_print(t_formats *mod)
{
	long long	num;
	long long	sign;

	num = va_arg(mod->args, long long);
	sign = 1 - 2 * (num < 0);
	if (mod->length == L)
		ft_putnbr((long)num);
	else if (mod->length == LL)
		ft_putnbr((long long)num);
	else if (mod->length == H)
		ft_putnbr((short)num);
	else if (mod->length == HH)
		ft_putnbr((signed char)num);
	num *= sign;
	if (sign == -1)
	{
		mod->sign = 0;
		mod->char_count += 1;
	}
	mod->num = &num;
	g_flagprint[mod->flag[0]](mod);
	mod->char_count += ft_uint_base_count((unsigned long long)num, 10);
}

void	ulength_print(t_formats *mod)
{
	unsigned long long	num;

	num = va_arg(mod->args, unsigned long long);
	if (mod->length == L)
		ft_putnbr((unsigned long)num);
	else if (mod->length == LL)
		ft_putnbr((unsigned long long)num);
	else if (mod->length == H)
		ft_putnbr((unsigned short)num);
	else if (mod->length == HH)
		ft_putnbr((unsigned char)num);
	mod->num = &num;
	g_flagprint[mod->flag[0]](mod);
	mod->char_count += ft_uint_base_count(num, 10);
}
