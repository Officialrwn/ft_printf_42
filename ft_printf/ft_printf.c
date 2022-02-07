/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/07 16:42:37 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	print_arg(va_list args, char c)
{
	int	i;

	i = 0;
	while (flags[i] && flags[i] != c)
		i++;
	if (flags[i] == '\0')
		i = -1;
	return (print_op[i](args));
}

int	check_format(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == ' ')
			{
				while (format[i + 1] == ' ')
					i++;
				printf("%c", ' ');
				count += 1;
			}	
			count += print_arg(args, format[++i]);
		}
		else
		{
			//printf("%c", format[i]);
			//count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;
	int i = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == ' ')
			{
				while (format[i + 1] == ' ')
					i++;
				printf("%c", ' ');
				count += 1;
			}	
			count += print_arg(args, format[++i]);
		}
		else
		{
			//printf("%c", format[i]);
			//count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int main (void)
{
	int a = ft_printf("test % i\n", 5);
	int b = printf("test % i\n", 5);
	printf("a: %d b: %d\n", a, b);
}