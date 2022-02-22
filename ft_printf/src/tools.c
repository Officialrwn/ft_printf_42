/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:44:08 by leotran           #+#    #+#             */
/*   Updated: 2022/02/22 18:28:08 by leo              ###   ########.fr       */
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
	mod->uint_flag[0] = FLAG_NULL;
	mod->uint_flag[1] = FLAG_NULL;
	mod->uint_flag[2] = FLAG_NULL;
	mod->flag[0] = ERROR_FLAG;
	mod->flag[1] = ERROR_FLAG;
	mod->length = LENGTH_NULL;
	mod->width = 0;
	mod->precision = 0;
	mod->specifier = 0;
	mod->char_count = 0;
	mod->formatcombo = 0;
	mod->num = NULL;
}

void	printformats(t_formats *mod)
{
	printf("\n\nflag0: %d [5 = FLAGNULL]\n", mod->flag[0]);
	printf("flag1: %d [5 = FLAGNULL]\n", mod->flag[1]);
	printf("width: %d\n", mod->width);
	printf("precision: %d\n", mod->precision);
	printf("length: %d [5 = LENGTH_NULL]\n", mod->length);
	printf("num: %s\n\n", mod->num);
	printf("specifier: %c\n\n", mod->specifier);
}

void	get_format_lengths(t_formats *mod)
{
	int	len;
	int	i;
	int	sign;

	sign = (mod->precision == 0 && mod->uint_flag[2] == PRECISION);
	len = (int)ft_strlen(mod->num) - (*mod->num == '-');
	if (mod->specifier == 'f')
	{
		if (*mod->num == '-' || (mod->formatcombo & (PLUS | SPACE)) != 0)
			len++;
		if ((mod->formatcombo & HASH) != 0 && sign == 1)
			len++;
		mod->width -= len;
	}
	else
	{
		i = ((mod->formatcombo & HASH) != 0 && mod->specifier == 'o');
		if (mod->precision > 0)
			mod->precision -= (len + i);
		if ((mod->formatcombo & DASH_HSP) != 0 || (*mod->num == '-'))
			len += 1 + ((mod->formatcombo & HASH) != 0 && mod->specifier != 'o');
		if (*mod->num == '0' && sign == 1)
		{
			*mod->num = '\0';
			len--;
		}	
		if (mod->width > 0)
			mod->width -= (len + mod->precision);
	}
	//printf("width: %d\n", mod->width);
	//printf("len: %d\n", len);
}
