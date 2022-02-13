/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/13 15:58:12 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*plus_print(t_formats *modifiers, void *num)
{
	long long	i;
	long long	sign;

	if ((modifiers->formatcombo ^ PLUS) != 0 \
		&& modifiers->uint_flag[0] == PLUS \
		&& (modifiers->formatcombo & HPSZD) == 0)
		return (NULL);
	i = *(long long *)num;
	sign = 1 - 2 * (i < 0);
	if (sign == 1)
		ft_putchar('+');
	else
		ft_putchar('-');
	modifiers->char_count += 1;
	*(long long *)num *= sign;
	return (num);
}

void	*hash_print(t_formats *modifiers, void *num)
{
	int	i;

	if ((modifiers->formatcombo ^ HASH) != 0 \
		&& modifiers->uint_flag[0] == HASH \
		&& (modifiers->formatcombo & HPSZD) == 0)
		return (NULL);
	i = 1;
	ft_putchar('0');
	if (modifiers->specifier != 'o')
	{
		ft_putchar(modifiers->specifier);
		i++;
	}
	modifiers->char_count += i;
	return (NULL);
}

void	*zero_print(t_formats *modifiers, void *num)
{
	long long	ilen;

	ilen = *(long long *)num;
	while (modifiers->width-- - ilen)
	{
		ft_putchar('0');
		modifiers->char_count += 1;
	}
	return (NULL);
}

void	*space_print(t_formats *modifiers, void *num)
{
	num = NULL;
	modifiers->char_count += custom_putchar(' ');
	return (NULL);
}

void	*dash_print(t_formats *modifiers, void *num)
{
	int	i;

	i = *(int *)num;
	if (modifiers->uint_flag[0] == DASH)
		ft_putnbr(i);
	while (--modifiers->width)
		modifiers->char_count += custom_putchar(' ');
	return (NULL);
}
