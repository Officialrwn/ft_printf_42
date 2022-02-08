/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:25:53 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 13:55:35 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define CONVERSION "cspdiouxX%"
# define FLAGS "hl# "

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

// Forbidden header
# include <stdio.h> 

int			int_print(va_list args);
int			char_print(va_list args);
int			str_print(va_list args);
int			custom_putchar(char c);
int			print_arg(va_list args, int c);
int			ft_printf(const char *format, ...);
int			check_format(const char *format, va_list args);
int			memaddr_print(va_list args);
const char	*is_space(const char *format);

typedef int			(*t_f)(va_list args);

static const t_f	g_print_func[16] = {
	char_print,
	str_print,
	memaddr_print
	int_print,
	int_print,
};

#endif
