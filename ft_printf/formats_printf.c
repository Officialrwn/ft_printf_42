/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/13 17:13:30 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*plus_print(t_formats *modifiers, void *num)
{
	long long	i;
	long long	sign;

	if ((modifiers->formatcombo & HPSZD) != 0)
		return (NULL);
	i = *(long long *)num;
	sign = 1 - 2 * (i < 0);
	if (sign == 1)
		ft_putchar('+');
	else
		ft_putchar('-');
	modifiers->char_count += 1;
	*(long long *)num *= sign;
	if (modifiers->uint_flag[0] == PLUS && modifiers->uint_flag[1] != 0)
		printf("callnextfn\n");
	return (num);
}

void	*hash_print(t_formats *modifiers, void *num)
{
	int	i;

	if ((modifiers->formatcombo & HPSZD) == 0)
		return (NULL);
	i = 1;
	ft_putchar('0');
	if (modifiers->specifier != 'o')
	{
		ft_putchar(modifiers->specifier);
		i++;
	}
	modifiers->char_count += i;
	if (modifiers->uint_flag[0] == HASH && modifiers->uint_flag[1] != 0)
		printf("callnextfn\n");
	return (NULL);
}

void	*zero_print(t_formats *modifiers, void *num)
{
	long long	ilen;

	if ((modifiers->formatcombo ^ ZERO) != 0)
		return (NULL);
	ilen = ft_uint_base_count(*(long long *)num, 10);
	while (modifiers->width-- - ilen)
	{
		ft_putchar('0');
		modifiers->char_count += 1;
	}
	return (NULL);
}

void	*space_print(t_formats *modifiers, void *num)
{
	if ((modifiers->formatcombo & HPSZD) == 0)
		return (NULL);
	num = NULL;
	modifiers->char_count += custom_putchar(' ');
	if (modifiers->uint_flag[0] == SPACE && modifiers->uint_flag[1] != 0)
		printf("callnextfn\n");
	return (NULL);
}

void	*dash_print(t_formats *modifiers, void *num)
{
	int	i;

	if ((modifiers->formatcombo & DHS) == 0)
		return (NULL);
	i = *(int *)num;
	
	//if (modifiers->uint_flag[0] == DASH)
		ft_putnbr(i);
	
	while (--modifiers->width)
		modifiers->char_count += custom_putchar(' ');
	
	if (modifiers->uint_flag[0] == DASH && modifiers->uint_flag[1] != 0)
		printf("callnextfn\n");
	return (NULL);
}
