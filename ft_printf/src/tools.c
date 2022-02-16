/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:44:08 by leotran           #+#    #+#             */
/*   Updated: 2022/02/16 13:40:30 by leotran          ###   ########.fr       */
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
	mod->uint_flag[0] = FLAGNULL;
	mod->uint_flag[1] = FLAGNULL;
	mod->flag[0] = ERROR_FLAG;
	mod->flag[1] = ERROR_FLAG;
	mod->width = 0;
	mod->precision = 0;
	mod->length = LENGTH_NULL;
	mod->specifier = 0;
	mod->char_count = 0;
	mod->formatcombo = 0;
	mod->num = NULL;
}

int	get_num_length(t_formats *mod)
{
	size_t	len;

	len = ft_strlen(mod->num);
	if ((mod->formatcombo & HASH) != 0 && mod->specifier != 'o')
		len += 2;
	else if ((mod->formatcombo & DASH_HSP) != 0)
		len++;
	return ((int)len);
}