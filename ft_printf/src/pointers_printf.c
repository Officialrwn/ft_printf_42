/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/20 03:19:04 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_print(t_formats *mod)
{
	char	*str;
	size_t	size;

	str = va_arg(mod->args, char *);
	size = ft_strlen(str);
	mod->char_count += (int)size;
	ft_putstr(str);
}

void	memaddr_print(t_formats *mod)
{
	unsigned long long	num;
	int					len;

	num = va_arg(mod->args, unsigned long long);
	mod->num = ft_uitoa_base(num, 16, 0);
	len = (int)ft_strlen(mod->num) + 2;
	mod->width -= len * (mod->width > len);
	if ((mod->formatcombo & DASH) == 0 && mod->width > 0)
		width_print(mod);
	mod->char_count += write(1, "0x", 2);
	custom_putstr(mod);
}

void	custom_putstr(t_formats *mod)
{
	int	i;
	int	sign;

	i = 0;
	sign = (((mod->formatcombo ^ DASH) & DASH_HSP) != 0);
	if (*mod->num == '-')
		i++;
	while (mod->num[i])
		mod->char_count += write(1, &mod->num[i++], 1);
	if (sign == 1 || mod->uint_flag[0] == DASH)
		width_print(mod);
}
