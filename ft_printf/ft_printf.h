/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:25:53 by leo               #+#    #+#             */
/*   Updated: 2022/02/12 19:48:58 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION "cspdiouxX%"
# define FLAGS "0# -+"
# define LENGTH "hhllL"
# define WIDTH 0
# define PRECISION 1

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

/* Forbidden header */
# include <stdio.h> 

/* %[flags][width][.precision][length]specifier */
/* as long as compare is not 0 (bits); */

typedef enum e_flags
{
	ZERO = 0x1,
	HASH = 0x2,
	SPACE = 0x4,
	HYPHEN = 0x8,
	PLUS = 0x10,
	FLAGNULL = 0x0
}	t_flags;

typedef enum e_length
{
	H = 0,
	HH = 1,
	L = 2,
	LL = 3,
	UPPERL = 4,
	LENGTH_NULL = 5,
}	t_length;

typedef struct s_formats
{
	t_flags			flag[3];
	t_length		length;
	const char		*tempformat;
	int				width;
	int				precision;
	int				specifier;
	size_t			char_count;
	u_int16_t		formatcombo;
}	t_formats;

void		get_formatcombo(t_formats *modifiers);

void		*plus_print(t_formats *modifiers, void *num, void *digitcount);
void		*hash_print(t_formats *modifiers, void *num, void *digitcount);
void		*zero_print(t_formats *modifiers, void *num, void *digitcount);
void		*space_print(t_formats *modifiers, void *num, void *digitcount);
void		*hyphen_print(t_formats *modifiers, void *num, void *digitcount);

void		error_print(t_formats *modifiers);
void		initialize_t_formats(t_formats *modifiers);

const char	*get_flag(const char *format, t_formats *modifiers);
const char	*get_length(const char *format, t_formats *modifiers);
const char	*get_width(const char *format, t_formats *modifiers, int flag);

int			get_formats(const char *format, va_list args);
int			get_specifier(va_list args, t_formats *modifiers, int c);
int			ft_printf(const char *format, ...);
int			char_print(va_list args, t_formats *modifiers);
int			str_print(va_list args, t_formats *modifiers);
int			memaddr_print(va_list args, t_formats *modifiers);
int			int_print(va_list args, t_formats *modifiers);
int			base_int_printf(va_list args, t_formats *modifiers);
int			oct_print(va_list args, t_formats *modifiers);
int			uint_print(va_list args, t_formats *modifiers);
int			hex_print_lower(va_list args, t_formats *modifiers);
int			hex_print_upper(va_list args, t_formats *modifiers);
int			percentage_putchar(va_list args, t_formats *modifiers);
int			custom_putchar(int c);

typedef int					(*t_printf)(va_list args, t_formats *modifiers);
typedef void*				(*t_flagprint)(t_formats *modifiers \
							, void *num, void *count);

static const t_printf		g_printf[16] = {
	char_print,
	str_print,
	memaddr_print,
	int_print,
	base_int_printf,
	uint_print,
	percentage_putchar,
};

static const t_flagprint	g_printflag[10] = {
	plus_print,
	hash_print,
	zero_print,
	space_print,
	hyphen_print
};

static const int g_conversion[11] = {
	0,
	1,
	2,
	3,
	3,
	4,
	5,
	4,
	4,
	6,
	-1
};

#endif
