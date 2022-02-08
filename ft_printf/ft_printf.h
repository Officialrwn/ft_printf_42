/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:25:53 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 18:08:48 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION "cspdiouxX%"
# define FLAGS "hl#-+ "

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

// Forbidden header
# include <stdio.h> 

int			get_flag(const char *format);
int			get_width(const char *format);
int			get_precision(const char *format);
int			get_length(const char *format);
int			get_specifier(const char *format);

int			char_print(va_list args);
int			str_print(va_list args);
int			memaddr_print(va_list args);
int			int_print(va_list args);
int			oct_print(va_list args);
int			print_arg(va_list args, int c);
int			uint_print(va_list args);
int			hex_print_lower(va_list args);
int			hex_print_upper(va_list args);
int			percentage_putchar(va_list args);

int			custom_putchar(char c);
int			ft_printf(const char *format, ...);
int			check_format(const char *format, va_list args);

const char	*is_space(const char *format);

typedef int			(*t_f)(va_list args);

static const t_f	g_print_func[16] = {
	char_print,
	str_print,
	memaddr_print,
	int_print,
	int_print,
	oct_print,
	uint_print,
	hex_print_lower,
	hex_print_upper,
	percentage_putchar
};

#endif
