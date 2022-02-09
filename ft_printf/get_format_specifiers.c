/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_specifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:05:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/09 02:10:50 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	get_flag(const char *format)
{
	t_flags	flag;

	flag = 0;
	while (FLAGS[flag])
	{
		if (FLAGS[flag] == *format)
			break ;
		flag++;
	}
	return (flag);
}

char	*get_width(const char *format)
{
	return (0);
}

char	*get_precision(const char *format)
{
	return (0);
}

char	*get_length(const char *format)
{
	return (0);
}

char	*get_specifier(const char *format)
{
	return (0);
}
