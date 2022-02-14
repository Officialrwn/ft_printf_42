/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:44:08 by leotran           #+#    #+#             */
/*   Updated: 2022/02/14 09:36:17 by leo              ###   ########.fr       */
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
