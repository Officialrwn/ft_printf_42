/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/07 15:42:28 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int print_arg(va_list args, char c)
{
	int i;

	i = 0;
	while (flags[i] && flags[i] != c)
		i++;
	if (flags[i] == '\0')
		i = -1;
	return (print_op[i](args));
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;
	int i = 0;
	int num_args = ft_strlen(format);

	while (format[i])
	{
		if (format[i] == '%')
			count += print_arg(args, format[++i]);
		else
		{
			printf("%c", format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int main (void)
{
	int a = ft_printf("test %d\n", 555555);
	int b = printf("test %d\n", 555555);
	printf("a: %d b: %d\n", a, b);
}