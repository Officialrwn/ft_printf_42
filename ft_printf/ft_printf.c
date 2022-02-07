/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/06 15:27:03 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int num_args = ft_strlen(format);

	for (int i = 0; i < num_args; i++)
	{
		if (format[i] == '%d')
		{
			int x = va_arg(args, int);
			printf("%d\n", x);
		}
		else if (format[i] == 'f')
		{
			double x = va_arg(args, double);
			printf("%f\n", x);
		}
	}
	va_end(args);
	return (1);
}

int main (void)
{
	ft_printf("hej %d c %c", 5, 'c');
}