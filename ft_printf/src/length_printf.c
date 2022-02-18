/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:45:26 by leotran           #+#    #+#             */
/*   Updated: 2022/02/18 17:24:58 by leotran          ###   ########.fr       */
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
	int	len;

	len = get_num_length(mod);
	if (*mod->num == '-' && (mod->uint_flag[0] & PLUS) != 0)
		len--;
	if (mod->width-- - len <= 0)
		return ;
	while (mod->width-- - len >= 0)
		custom_putchar(mod, ' ');
}

void	check_precision(t_formats *mod)
{
	int	len;
	int	sign;

	sign = (mod->num[0] == '-');
	len = mod->precision + sign - (int)ft_strlen(mod->num);
	if (sign)
		ft_putchar('-');
	while (len--)
		mod->char_count += write(1, "0", 1);
}
