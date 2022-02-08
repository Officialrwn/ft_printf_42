/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 19:43:32 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(va_list args, int c)
{
	int	i;

	i = 0;
	while (CONVERSION[i] && CONVERSION[i] != c)
		i++;
	if (CONVERSION[i] == '\0')
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

int	get_formats(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i++] == '%')
		{
			get_flag(&format[i]);
			printf("%c\n", format[i]);
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = get_formats(format, args);
	va_end(args);
	return (count);
}
