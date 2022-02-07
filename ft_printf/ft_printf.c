/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/07 22:57:41 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	print_arg(va_list args, int c)
{
	int	i;

	i = 0;
	while (FLAGS[i] && FLAGS[i] != c)
		i++;
	if (FLAGS[i] == '\0')
	{
		ft_putchar('%');
		ft_putchar(c);
		return (2);
	}
	return (g_print_func[i](args));
}

const char	*is_space(const char *format)
{
	int	i;

	i = 0;
	while (format[i] && format[i + 1] == ' ')
		i++;
	return (&format[i]);
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
				format = is_space(&format[i]);
				count += custom_putchar(' ');
				i = 0;
			}	
			count += print_arg(args, format[++i]);
		}
		else if (format[i] == '\\' && format[i + 1] == 'n')
			count += custom_putchar('\n');
		else
			count += custom_putchar(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = check_format(format, args);
	va_end(args);
	return (count);
}

int	main(void)
{
	int	a;
	int	b;
	char c = 'A';
	int *p;
	a = ft_printf("test % d\n", 5);
	b = printf("test % d\n", 5);
	printf("a: %d b: %d\n", a, b);
	printf("%p\n", &c);
	ft_putnbr((long int) &c);
}
