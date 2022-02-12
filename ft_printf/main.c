/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:04:46 by leo               #+#    #+#             */
/*   Updated: 2022/02/12 14:06:57 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;

	a = -5;
	int ret = ft_printf("test nr: %d HEHEH\n", 2147483650);
	printf("%d\n", ret);
	ret = printf("test nr: %ld HEHEH\n", -2147483650);
	printf("%d\n", ret);
	return (0);
}
