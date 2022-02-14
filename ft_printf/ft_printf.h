/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:25:53 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 12:09:49 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION "cspdiouxX%"
# define FLAGS 		"0# -+"
# define LENGTH 	"hhllL"
# define WIDTH 		0
# define PRECISION 	1

# define HPSZD		9
# define DHS		12

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

/* Forbidden header */
# include <stdio.h> 

/* %[flags][width][.precision][length]specifier */
/* as long as compare is not 0 (bits); */

typedef enum e_conversions
{
	C,
	S,
	P,
	D,
	I,
	O,
	U,
	X,
	XX,
	PERCENT,
	CONV_NULL
}	t_conversions;

typedef enum e_flags
{
	ZERO = 1,
	HASH = 2,
	SPACE = 4,
	DASH = 8,
	PLUS = 16,
	FLAGNULL = 0
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
	t_flags			uint_flag[3];
	t_length		length;
	const char		*tempformat;
	int				width;
	int				precision;
	int				specifier;
	int				flag[2];
	size_t			char_count;
	u_int16_t		formatcombo;
	void			*num;
}	t_formats;

int			get_formatcombo(t_formats *mod);

void		plus_print(t_formats *mod);
void		hash_print(t_formats *mod);
void		zero_print(t_formats *mod);
void		space_print(t_formats *mod);
void		dash_print(t_formats *mod);

void		error_print(t_formats *mod);
void		initialize_t_formats(t_formats *mod);

const char	*get_flag(const char *format, t_formats *mod);
const char	*get_length(const char *format, t_formats *mod);
const char	*get_width(const char *format, t_formats *mod, int flag);

int			get_formats(const char *format, va_list args);
int			get_specifier(va_list args, t_formats *mod, int c);
int			ft_printf(const char *format, ...);

void		length_print(t_formats *mod);
void		char_print(va_list args, t_formats *mod);
void		str_print(va_list args, t_formats *mod);
void		memaddr_print(va_list args, t_formats *mod);
void		int_print(va_list args, t_formats *mod);
void		base_int_printf(va_list args, t_formats *mod);
void		uint_print(va_list args, t_formats *mod);
void		percentage_putchar(va_list args, t_formats *mod);
int			custom_putchar(int c);

typedef void				(*t_printf)(va_list args, t_formats *mod);
typedef void				(*t_flagprint)(t_formats *mod);

static const t_printf		g_printf[8] = {
	char_print,
	str_print,
	memaddr_print,
	int_print,
	base_int_printf,
	uint_print,
	percentage_putchar,
};

static const t_flagprint	g_flagprint[5] = {
	zero_print,
	hash_print,
	space_print,
	dash_print,
	plus_print
};

static const int			g_conversion[11] = {
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
