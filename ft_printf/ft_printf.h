/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:25:53 by leo               #+#    #+#             */
/*   Updated: 2022/02/09 14:20:59 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION "cspdiouxX%"
# define FLAGS "#0- +"
# define LENGTH "hhllL"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

// Forbidden header
# include <stdio.h> 

typedef int			(*t_f)(va_list args);

// %[flags][width][.precision][length]specifier

typedef enum e_flags
{
	HASH = 0,
	ZERO = 1,
	DASH = 2,
	SPACE = 3,
	PLUS = 4,
	FLAGNUL = 5
}	t_flags;

typedef enum e_length
{
	H = 0,
	HH = 1,
	L = 2,
	LL = 3,
	UPPERL = 4,
	LENGTHNUL = 5
}	t_length;

typedef struct	s_formats
{
	t_flags flag;
	t_length length;
	int	width;
	int precision;
}	t_formats;

void	get_flag(const char *format, t_formats *modifiers);
void	get_length(const char *format, t_formats *modifiers);
void	get_specifier(const char *format, t_formats *modifiers);
const char *get_width(const char *format, t_formats *modifiers);
int		get_precision(const char *format, t_formats *modifiers);
int		get_formats(const char *format, va_list args);

int		char_print(va_list args);
int		str_print(va_list args);
int		memaddr_print(va_list args);
int		int_print(va_list args);
int		oct_print(va_list args);
int		print_arg(va_list args, int c);
int		uint_print(va_list args);
int		hex_print_lower(va_list args);
int		hex_print_upper(va_list args);
int		percentage_putchar(va_list args);

int		custom_putchar(char c);
int		ft_printf(const char *format, ...);

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