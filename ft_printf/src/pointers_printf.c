/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/18 18:48:05 by leotran          ###   ########.fr       */
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
		ft_strdel(&mod->num);
	}
	ft_strdel(&temp);
}

void	custom_putstr(t_formats *mod, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && (mod->precision > (int)ft_strlen(mod->num) \
	|| ((mod->formatcombo & ZERO) != 0 && mod->width > 0)))
		i++;
	while(str[i])
		mod->char_count += write(1, &str[i++], 1);
}
