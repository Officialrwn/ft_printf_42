/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 09:36:20 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_print(va_list args, t_formats *mod)
{
	ft_putchar(va_arg(args, int));
	return (1);
}

int	custom_putchar(int c)
{
	ft_putchar(c);
	return (1);
}

int	percentage_putchar(va_list args, t_formats *mod)
{
	ft_putchar('%');
	return (1);
}

void	error_print(t_formats *mod)
{
	char	*temp;
	char	c;
	int		i;

	temp = (char *)mod->tempformat;
	c = mod->specifier;
	i = 0;
	while (temp[i])
	{
		mod->char_count += custom_putchar(temp[i++]);
		if (temp[i - 1] == c)
			break ;
	}
}
