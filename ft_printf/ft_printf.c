/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/11 12:22:37 by leotran          ###   ########.fr       */
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
	printf("flag0: %d\n", modifiers.flag[0]);
	printf("flag1: %d\n", modifiers.flag[1]);
	get_formatcombo(&modifiers);
	printf("flagcombo: %d\n", modifiers.formatcombo);
	return (modifiers.char_count);
}

