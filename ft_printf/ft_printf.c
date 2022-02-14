/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 09:36:45 by leo              ###   ########.fr       */
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
	t_formats	mod;

	initialize_t_formats(&mod);
	while (*format)
	{
		if (*format == '%')
		{
			mod.tempformat = format;
			format = get_flag(&(*++format), &mod);
			get_formatcombo(&mod);
			if ((*format) == '.')
				format = get_width(&(*++format), &mod, PRECISION);
			format = get_length(&(*format), &mod);
			mod.specifier = *format;
			if (!(get_specifier(args, &mod, *format++)))
				error_print(&mod);
		}
		mod.char_count += custom_putchar(*format++);
	}
	return (mod.char_count);
}
