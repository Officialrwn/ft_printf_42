/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_type_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:00:57 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 10:34:59 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	str_print(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr(str);
	return (ft_strlen(str));
}

/* int	memaddr_print(va_list args)
{
	long long	llnum;

	llnum = va_arg(args, void *)
} */