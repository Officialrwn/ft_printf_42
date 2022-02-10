/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/10 19:23:35 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = get_formats(format, args);
	va_end(args);
	return (count);
}

int	get_formats(const char *format, va_list args)
{
	t_flags		flag;
	t_formats	modifiers;

	initialize_t_formats(&modifiers);
	while (*format)
	{
		if (*format == '%')
		{
			modifiers.tempformat = format;
			format = get_flag(&(*++format), &modifiers);
			if ((*format) == '.')
				format = get_width(&(*++format), &modifiers, PRECISION);
			format = get_length(&(*format), &modifiers);
			modifiers.specifier = *format;
			if (!(get_specifier(args, &modifiers, *format++)))
				error_print(&modifiers);
		}
		modifiers.char_count += custom_putchar(*format++);
	}
	return (modifiers.char_count);
}

void	initialize_t_formats(t_formats *modifiers)
{
	int	i;

	i = 3;
	while (i--)
		modifiers->flag[i] = FLAGNULL;
	modifiers->length = LENGTHNULL;
	modifiers->tempformat = NULL;
	modifiers->width = 0;
	modifiers->precision = 0;
	modifiers->specifier = 0;
	modifiers->char_count = 0;
}
