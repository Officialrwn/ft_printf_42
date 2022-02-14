/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_specifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:05:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 09:36:27 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*get_flag(const char *format, t_formats *mod)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == *format && mod->uint_flag[j] == FLAGNULL && j != 2)
		{
			mod->uint_flag[j] = 1 << i;
			mod->flag[j++] = i;
			c = *format;
			while (*format == c)
				format++;
			i = 0;
			continue ;
		}	
		i++;
	}
	return (get_width(&(*format++), mod, WIDTH));
}

const char	*get_width(const char *format, t_formats *mod, int flag)
{
	int		i;
	char	*temp;

	i = 0;
	while (*format == '0')
		format++;
	if (ft_isdigit(*format))
	{
		while (format[i] && ft_isdigit(format[i]))
			i++;
		temp = ft_strsub(format, 0, i);
		if (flag == WIDTH)
			mod->width = ft_atoi(temp);
		else
			mod->precision = ft_atoi(temp);
		ft_strdel(&temp);
	}
	return (&(format[i]));
}

const char	*get_length(const char *format, t_formats *mod)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (LENGTH[i])
	{
		if (LENGTH[i] == format[j] && mod->length == LENGTH_NULL)
		{
			mod->length = i;
			format++;
			if (format[j] == format[j - 1])
			{
				mod->length = i + 1;
				format++;
			}	
		}
		i++;
	}
	return (&(*format));
}

int	get_specifier(va_list args, t_formats *mod, int c)
{
	int	i;

	i = 0;
	while (CONVERSION[i])
	{
		if (CONVERSION[i] == c)
		{
			mod->specifier = c;
			if (g_conversion[i] == -1)
				break ;
			return (g_printf[g_conversion[i]](args, mod));
		}
		i++;
	}
	return (0);
}
