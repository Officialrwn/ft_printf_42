/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:55:01 by leo               #+#    #+#             */
/*   Updated: 2022/02/09 16:15:23 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(va_list args, int c)
{
	int	i;

	i = 0;
	while (CONVERSION[i] && CONVERSION[i] != c)
		i++;
	if (CONVERSION[i] == '\0')
	{
		ft_putchar('%');
		ft_putchar(c);
		return (2);
	}
	return (g_print_func[i](args));
}

void	initialize_t_formats(t_formats modifiers)
{
	int	i;

	i = 0;
	while (modifiers.flag[i])
		modifiers.flag[i++] = FLAGNUL;
	modifiers.length = LENGTHNUL;
	modifiers.width = 0;
	modifiers.precision = 0;
}

int	get_formats(const char *format, va_list args)
{
	int			count;
	t_flags		flag;
	t_formats	modifiers;

	count = 0;
	initialize_t_formats(modifiers);
	while (*format)
	{
		if (*format == '%')
		{
			get_flag(&(*++format), &modifiers);
			flag = modifiers.flag[0];
			if (flag == DASH || flag == ZERO || ft_isdigit(*format))
				format = get_width(&(*format), &modifiers);
		}
		count += custom_putchar(*format);
		format++;
	}
	printf("FLAG0: %d\n", modifiers.flag[0]);
	printf("FLAG1: %d\n", modifiers.flag[1]);
	printf("FLAG2: %d\n", modifiers.flag[2]);
	printf("FLAG3: %d\n", modifiers.flag[3]);
	printf("FLAG4: %d\n", modifiers.flag[4]);
	printf("Width: %d\n", modifiers.width);


	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = get_formats(format, args);
	va_end(args);
	return (count);
}
