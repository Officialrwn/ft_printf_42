/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:44:08 by leotran           #+#    #+#             */
/*   Updated: 2022/02/13 15:57:07 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_formatcombo(t_formats *modifiers)
{
	u_int16_t	flag0;
	u_int16_t	flag1;

	flag0 = modifiers->uint_flag[0];
	flag1 = modifiers->uint_flag[1];
	modifiers->formatcombo = flag0 | flag1;
	return (0);
}

void	initialize_t_formats(t_formats *modifiers)
{
	int	i;

	i = 3;
	while (i--)
		modifiers->uint_flag[i] = FLAGNULL;
	modifiers->length = LENGTH_NULL;
	modifiers->tempformat = NULL;
	modifiers->width = 0;
	modifiers->precision = 0;
	modifiers->specifier = 0;
	modifiers->flag[0] = 0;
	modifiers->flag[1] = 0;
	modifiers->char_count = 0;
	modifiers->formatcombo = 0;
	modifiers->num = NULL;
}
