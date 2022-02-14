/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 21:47:44 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_formats	mod;
	char		*str;

	str = (char *)format;
	initialize_t_formats(&mod);
	va_start(mod.args, format);
	get_formats(str, &mod);
	va_end(mod.args);
	return (mod.char_count);
}

void	get_formats(char *format, t_formats *mod)
{
	while (*format)
	{
		if (*format == '%')
		{
			mod->tempformat = format;
			format = get_flag(&(*++format), mod);
			get_formatcombo(mod);
			if ((*format) == '.')
				format = get_width(&(*++format), mod, PRECISION);
			format = get_length(&(*format), mod);
			mod->specifier = *format;
			if (!(get_specifier(mod, *format++)))
				printf("invalid specifier\n");
		}
		custom_putchar(mod, *format++);
	}
}
