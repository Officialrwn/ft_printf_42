/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:39:20 by leotran           #+#    #+#             */
/*   Updated: 2022/02/07 16:42:30 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	int_print(va_list args)
{
	int count = 0;
	int x = va_arg(args, int);
	printf("%d", x);
	while (x % 10 > 0)
	{
		x /= 10;
		count++;
	}	
	return (count);
}

int	char_print(va_list args)
{
	char c = va_arg(args, int);
	printf("%c", c);
	return (1);
}

int	str_print(va_list args)
{
	char *str = va_arg(args, char *);
	printf("%s", str);
	return (ft_strlen(str));
}
