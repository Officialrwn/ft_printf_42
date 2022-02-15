/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/16 00:46:36 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_formats	mod;
	char		*str;

	initialize_t_formats(&mod);
	va_start(mod.args, format);
	str = (char *)format;
	get_formats(str, &mod);
	mod.num = &(*--mod.num);
	ft_strdel(&mod.num);
	va_end(mod.args);
	return (mod.char_count);
}

void	get_formats(char *format, t_formats *mod)
{
	while (*format)
	{
		if (*format == '%')
		{
			format = get_flag(&(*++format), mod);
			get_formatcombo(mod);
			if ((*format) == '.')
				format = get_width(&(*++format), mod, PRECISION);
			format = get_length(&(*format), mod);
			mod->specifier = *format;
			if (get_specifier(mod, *format++) == 0)
				ft_putstr("invalid specifier\n");
		}
		custom_putchar(mod, *format++);
	}
}
