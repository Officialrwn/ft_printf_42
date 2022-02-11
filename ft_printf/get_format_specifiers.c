/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_specifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:05:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/11 10:48:07 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*get_flag(const char *format, t_formats *modifiers)
{
	t_flags	flag;
	int		i;
	char	c;
	flag = 0;
	i = 0;
	while (FLAGS[flag])
	{
		if (FLAGS[flag] == *format && modifiers->flag[i] == FLAGNULL && i != 2)
		{
			modifiers->flag[i++] = 1 << flag;
			c = *format;
			while (*format == c)
				format++;
			flag = 0;
			continue ;
		}	
		flag++;
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
		if (LENGTH[i] == format[j] && modifiers->length == LENGTHNULL)
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
			modifiers->char_count += g_print_func[i](args, modifiers);
			return (1);
		}
		i++;
	}
	return (0);
}
