/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:25:53 by leo               #+#    #+#             */
/*   Updated: 2022/02/18 11:25:24 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION "cspdiouxX%"
# define FLAGS 		"0# -+"
# define LENGTH 	"hhllL"
# define WIDTH 		0
# define PRECISION 	1
# define ERROR_FLAG	5

# define DASH_HSP	22
# define DS			12
# define HPS_ZD		9
# define DASH_HS	6

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

/* Forbidden header */
# include <stdio.h> 

/* %[flags][width][.precision][length]specifier */
/* as long as compare is not 0 (bits); */

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
	u_int16_t		formatcombo;
	u_int16_t		uint_flag[2];
	va_list			args;
	char			*num;
	int				flag[2];
	int				width;
	int				precision;
	int				length;
	char			specifier;
	int				char_count;
}	t_formats;

void 	printformats(t_formats *mod);
void	plus_print(t_formats *mod);
void	hash_print(t_formats *mod);
void	zero_print(t_formats *mod);
void	space_print(t_formats *mod);
void	dash_print(t_formats *mod);
void	error_print(t_formats *mod);
void	check_precision(t_formats *mod, int i, int j);


char	*get_flag(char *format, t_formats *mod);
char	*get_length(char *format, t_formats *mod);
char	*get_width(char *format, t_formats *mod, int flag);

void	initialize_t_formats(t_formats *mod);
void	get_formats(char *format, t_formats *mod);
int		get_specifier(t_formats *mod, char c);
int		ft_printf(const char *format, ...);
int		get_formatcombo(t_formats *mod);
int		get_num_length(t_formats *mod);

void	width_print(t_formats *mod);
void	ulength_print(t_formats *mod);
void	length_print(t_formats *mod);
void	char_print(t_formats *mod);
void	str_print(t_formats *mod);
void	memaddr_print(t_formats *mod);
void	int_print(t_formats *mod);
void	base_int_printf(t_formats *mod);
void	uint_print(t_formats *mod);
void	percentage_putchar(t_formats *mod);
void	custom_putchar(t_formats *mod, int c);
void	custom_putstr(t_formats *mod, char *str);

typedef void				(*t_printf)(t_formats *mod);
typedef void				(*t_flagprint)(t_formats *mod);

static const t_printf		g_printf[8] = {
	char_print,
	str_print,
	memaddr_print,
	int_print,
	base_int_printf,
	uint_print,
	percentage_putchar
};

static const t_flagprint	g_flagprint[6] = {
	zero_print,
	hash_print,
	space_print,
	dash_print,
	plus_print,
	error_print
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
