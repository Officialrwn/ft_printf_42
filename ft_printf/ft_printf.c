/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/10 05:22:18 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(va_list args, t_formats *modifiers, int c)
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
	return (g_print_func[i](args, modifiers));
}

void	initialize_t_formats(t_formats *modifiers)
{
	int	i;

	i = 3;
	while (i--)
		modifiers->flag[i] = FLAGNULL;
	modifiers->length = LENGTHNULL;
	modifiers->width = 0;
	modifiers->precision = 0;
}

int	get_formats(const char *format, va_list args)
{
	int			count;
	t_flags		flag;
	t_formats	modifiers;

	count = 0;
	initialize_t_formats(&modifiers);
	while (*format)
	{
		if (*format == '%')
		{
			format = get_flag(&(*++format), &modifiers);
			if ((*format++) == '.')
				format = get_width(&(*format), &modifiers, PRECISION);
			format = get_length(&(*format), &modifiers);
			get_specifier(args, &modifiers, *format++);
		}
		count += custom_putchar(*format);
		format++;
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
