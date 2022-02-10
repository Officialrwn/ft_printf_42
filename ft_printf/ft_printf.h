/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:25:53 by leo               #+#    #+#             */
/*   Updated: 2022/02/10 05:18:52 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION "cspdiouxX%"
# define FLAGS "#0- +"
# define LENGTH "hhllL"
# define WIDTH 0
# define PRECISION 1

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

// Forbidden header
# include <stdio.h> 

// %[flags][width][.precision][length]specifier

typedef enum e_flags
{
	HASH = 0,
	ZERO = 1,
	DASH = 2,
	SPACE = 3,
	PLUS = 4,
	FLAGNULL = 5
}	t_flags;

typedef enum e_length
{
	H = 0,
	HH = 1,
	L = 2,
	LL = 3,
	UPPERL = 4,
	LENGTHNULL = 5
}	t_length;

typedef struct s_formats
{
	t_flags		flag[3];
	t_length	length;
	int			width;
	int			precision;
}	t_formats;

void		initialize_t_formats(t_formats *modifiers);

const char	*get_flag(const char *format, t_formats *modifiers);
const char	*get_length(const char *format, t_formats *modifiers);
const char	*get_width(const char *format, t_formats *modifiers, int flag);
int			get_formats(const char *format, va_list args);
int			get_specifier(va_list args, t_formats *modifiers, int c);

int			ft_printf(const char *format, ...);
int			char_print(va_list args, t_formats *format);
int			str_print(va_list args, t_formats *format);
int			memaddr_print(va_list args, t_formats *format);
int			int_print(va_list args, t_formats *format);
int			oct_print(va_list args, t_formats *format);
int			uint_print(va_list args, t_formats *format);
int			hex_print_lower(va_list args, t_formats *format);
int			hex_print_upper(va_list args, t_formats *format);
int			percentage_putchar(va_list args, t_formats *format);
int			custom_putchar(char c);
int			print_arg(va_list args, t_formats *modifiers, int c);

typedef int			(*t_f)(va_list args, t_formats *format);

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
