/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/16 13:50:28 by leotran          ###   ########.fr       */
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
	char				*temp;

	num = va_arg(mod->args, unsigned long long);
	temp = ft_uitoa_base(num, 16, 0);
	mod->num = ft_strjoin("0x", temp);
	if (mod->uint_flag[0] == DASH)
		dash_print(mod);
	else
	{
		if (mod->width > 0)
			width_print(mod);
		custom_putstr(mod, mod->num);
		ft_strdel(&temp);
		ft_strdel(&mod->num);
	}
}

void	custom_putstr(t_formats *mod, char *str)
{
	size_t	size;

	size = ft_strlen(str);
	mod->char_count += (int)size;
	ft_putstr(str);
}
