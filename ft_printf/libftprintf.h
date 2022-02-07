/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:25:53 by leo               #+#    #+#             */
/*   Updated: 2022/02/07 21:53:50 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

# define FLAGS "dics"

int			int_print(va_list args);
int			char_print(va_list args);
int			str_print(va_list args);
int			custom_putchar(char c);
const char	*is_space(const char *format);

typedef int			(*t_f)(va_list args);

static const t_f	g_print_func[4] = {
	int_print,
	int_print,
	char_print,
	str_print
};

#endif
