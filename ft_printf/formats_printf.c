/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 14:26:16 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//if flag0 = plus then ilen - 1;
void	zero_print(t_formats *mod)
{
	long long	ilen;
	long long	num;

	num = *(long long *)mod->num;
	if (mod->width <= 0)
		return ;
	ilen = ft_uint_base_count(*(long long *)num, 10);
	while (mod->width-- - ilen)
	{
		ft_putchar('0');
		mod->char_count += 1;
	}
}

void	hash_print(t_formats *mod)
{
	int	flag;

	flag = 0;
	if (mod->uint_flag[0] == HASH && (mod->formatcombo & HPSZD) != 0)
		flag = 1;
	mod->char_count += custom_putchar('0');
	if (mod->specifier != 'o')
		mod->char_count += custom_putchar(mod->specifier);
	if (flag == 1 && mod->uint_flag[1] != 0)
		printf("callnextfn\n");
}

void	space_print(t_formats *mod)
{
	int	flag;

	flag = 0;
	if (mod->uint_flag[0] == SPACE && (mod->formatcombo & HPSZD) != 0)
		flag = 1;
	mod->char_count += custom_putchar(' ');
	if (flag == 1 && mod->uint_flag[1] != 0)
		printf("callnextfn\n");
}

void	dash_print(t_formats *mod)
{
	long long	num;

	num = *(long long *)mod->num;
	if ((mod->formatcombo & DHS) == 0 || mod->width <= 0)
		return ;
	if ((mod->formatcombo & DASH) == 0)
		ft_putnbr(num);
	while (--mod->width)
		mod->char_count += custom_putchar(' ');
	if (mod->uint_flag[0] == DASH && mod->uint_flag[1] != 0)
		printf("callnextfn\n");
}

void	plus_print(t_formats *mod)
{
	int			flag;
	int			j;

	flag = 0;
	j = mod->flag[1];
	if (mod->uint_flag[0] == PLUS && (mod->formatcombo & HPSZD) != 0)
		flag = 1;
	if (mod->sign == 1)
		mod->char_count += custom_putchar('+');
	if (flag == 1 && mod->uint_flag[1] != 0)
		printf("callnextfn\n");
}
