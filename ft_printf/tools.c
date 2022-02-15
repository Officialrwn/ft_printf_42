/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:44:08 by leotran           #+#    #+#             */
/*   Updated: 2022/02/15 08:42:34 by leo              ###   ########.fr       */
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
}

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
		ft_putnbr((unsigned long)num);
	else if (mod->length == H)
		ft_putnbr((unsigned short)num);
	else if (mod->length == HH)
		ft_putnbr((unsigned char)num);
	else
		ft_putnbr((unsigned long long)num);
	mod->char_count += ft_uint_base_count(num, 10);
}

int	get_num_length(t_formats *mod)
{
	size_t	len;

	len = ft_strlen(mod->num);
	if (*mod->num == '-')
	{
		custom_putchar(mod, '-');
		mod->num = &(*++mod->num);
	}
	else if ((mod->formatcombo & HASH) != 0 && mod->specifier != 'o')
		len += 2;
	else if ((mod->formatcombo & HSP) != 0)
		len++;
	return ((int)len);
}
