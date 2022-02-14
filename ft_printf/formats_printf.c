/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 09:38:22 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*zero_print(t_formats *mod, void *num)
{
	long long	ilen;

	if (mod->width <= 0)
		return (NULL);
	ilen = ft_uint_base_count(*(long long *)num, 10);
	while (mod->width-- - ilen)
	{
		ft_putchar('0');
		mod->char_count += 1;
	}
	return (NULL);
}

void	*hash_print(t_formats *mod, void *num)
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
	return (NULL);
}

void	*space_print(t_formats *mod, void *num)
{
	int	flag;

	flag = 0;
	if (mod->uint_flag[0] == SPACE && (mod->formatcombo & HPSZD) != 0)
		flag = 1;
	num = NULL;
	mod->char_count += custom_putchar(' ');
	if (flag == 1 && mod->uint_flag[1] != 0)
		printf("callnextfn\n");
	return (NULL);
}

void	*dash_print(t_formats *mod, void *num)
{
	int	i;

	if ((mod->formatcombo & DHS) == 0 || mod->width <= 0)
		return (NULL);
	i = *(int *)num;
	if ((mod->formatcombo & DASH) == 0)
		ft_putnbr(i);
	while (--mod->width)
		mod->char_count += custom_putchar(' ');
	if (mod->uint_flag[0] == DASH && mod->uint_flag[1] != 0)
		printf("callnextfn\n");
	return (NULL);
}

void	*plus_print(t_formats *mod, void *num)
{
	long long	i;
	long long	sign;
	int			flag;

	flag = 0;
	if (mod->uint_flag[0] == PLUS && (mod->formatcombo & HPSZD) != 0)
		flag = 1;
	i = *(long long *)num;
	sign = 1 - 2 * (i < 0);
	if (sign == 1)
		ft_putchar('+');
	else
		ft_putchar('-');
	mod->char_count += 1;
	*(long long *)num *= sign;
	if (flag == 1 && mod->uint_flag[1] != 0)
		printf("callnextfn\n");
	return (num);
}
