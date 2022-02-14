/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 11:51:28 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_print(va_list args, t_formats *mod)
{
	ft_putchar(va_arg(args, int));
}

int	custom_putchar(int c)
{
	ft_putchar(c);
	return (1);
}

void	percentage_putchar(va_list args, t_formats *mod)
{
	ft_putchar('%');
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
