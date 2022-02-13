/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_specifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:05:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/13 00:47:13 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*get_flag(const char *format, t_formats *modifiers)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == *format && modifiers->uint_flag[j] == FLAGNULL && j != 2)
		{
			modifiers->uint_flag[j] = 1 << i;
			modifiers->flag[j++] = i;
			c = *format;
			while (*format == c)
				format++;
			i = 0;
			continue ;
		}	
		i++;
	}
	return (get_width(&(*format++), modifiers, WIDTH));
}

const char	*get_width(const char *format, t_formats *modifiers, int flag)
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
			modifiers->width = ft_atoi(temp);
		else
			modifiers->precision = ft_atoi(temp);
		ft_strdel(&temp);
	}
	return (&(format[i]));
}

const char	*get_length(const char *format, t_formats *modifiers)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (LENGTH[i])
	{
		if (LENGTH[i] == format[j] && modifiers->length == LENGTH_NULL)
		{
			modifiers->length = i;
			format++;
			if (format[j] == format[j - 1])
			{
				modifiers->length = i + 1;
				format++;
			}	
		}
		i++;
	}
	return (&(*format));
}

int	get_specifier(va_list args, t_formats *modifiers, int c)
{
	int	i;

	i = 0;
	while (CONVERSION[i])
	{
		if (CONVERSION[i] == c)
		{
			modifiers->specifier = c;
			if (g_conversion[i] == -1)
				break ;
			return (g_printf[g_conversion[i]](args, modifiers));
		}
		i++;
	}
	return (0);
}
