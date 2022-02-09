/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_specifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:05:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/09 14:23:14 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag(const char *format, t_formats *modifiers)
{
	t_flags	flag;

	flag = 0;
	while (FLAGS[flag])
	{
		if (FLAGS[flag] == *format)
			break ;
		flag++;
	}
	modifiers->flag = flag;
}

const char	*get_width(const char *format, t_formats *modifiers)
{
	int		i;
	char	*temp;

	i = 0;
	if (*format == '-')
		format++;
	while(format[i] && ft_isdigit(format[i]))
		i++;
	temp = ft_strsub(format, 0, i);
	modifiers->width = ft_atoi(temp);
	ft_strdel(&temp);
	return (&(format[i]));
}

int	get_precision(const char *format, t_formats *modifiers)
{
	return (0);
}

void	get_length(const char *format, t_formats *modifiers)
{
	return ;
}

void	get_specifier(const char *format, t_formats *modifiers)
{
	return ;
}
