/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:44:08 by leotran           #+#    #+#             */
/*   Updated: 2022/02/12 19:21:33 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_formatcombo(t_formats *modifiers)
{
	u_int16_t	flag0;
	u_int16_t	flag1;
	u_int16_t	length;

	flag0 = modifiers->flag[0];
	flag1 = modifiers->flag[1];
	length = modifiers->length;
	modifiers->formatcombo = flag0 | flag1;
}

void	initialize_t_formats(t_formats *modifiers)
{
	int	i;

	i = 3;
	while (i--)
		modifiers->flag[i] = FLAGNULL;
	modifiers->length = LENGTH_NULL;
	modifiers->tempformat = NULL;
	modifiers->width = 0;
	modifiers->precision = 0;
	modifiers->specifier = 0;
	modifiers->char_count = 0;
	modifiers->formatcombo = 0;
}
