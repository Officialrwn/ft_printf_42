/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/25 14:21:33 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_formats	mod;
	char		*str;

	reset_t_formats(&mod, 1);
	va_start(mod.args, format);
	str = (char *)format;
	get_formats(str, &mod);
	va_end(mod.args);
	return (mod.char_count);
}

void	get_formats(char *format, t_formats *mod)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*++format == '\0')
				return ;
			format = get_flag(&(*format), mod);
			if ((*format) == '.')
				format = get_width(&(*format), mod, PRECISION);
			format = get_length(&(*format), mod);
			if (get_specifier(mod, *format))
			{
				format++;
				reset_t_formats(mod, 0);
				continue ;
			}
		}
		if (*format != '\0')
			mod->char_count += write(1, &(*format++), 1);
	}
}
