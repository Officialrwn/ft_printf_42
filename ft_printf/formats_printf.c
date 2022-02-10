/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/10 21:25:55 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*plus_print(t_formats *modifiers, void *num)
{
	int	i;

	i = *(int *)num;
	if (i >= 0)
		ft_putchar('+');
	else
	{
		i *= -1;
		ft_putchar('-');
	}
	modifiers->char_count += 1;
	num = &i;
	return (num);
}

void	*hash_print(t_formats *modifiers, void *num)
{
	int	i;

	i = 1;
	num = NULL;
	ft_putchar('0');
	if (modifiers->specifier != 'o')
	{
		ft_putchar(modifiers->specifier);
		i++;
	}
	modifiers->char_count += i;
	return (num);
}

void	*zero_print(t_formats *modifiers, void *num)
{
	int	ilen;
	int	i;

	ilen = *(int *)num;
	i = 0;
	while (modifiers->width - ilen++ > 0)
	{
		ft_putchar('0');
		i++;
	}
	modifiers->char_count += i;
	return (NULL);
}
