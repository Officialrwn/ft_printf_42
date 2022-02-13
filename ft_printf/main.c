/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:04:46 by leo               #+#    #+#             */
/*   Updated: 2022/02/13 17:06:53 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	unsigned char b = 65;

	a = -5;
	int ret = ft_printf("test nr: %0#5d HEHEH\n", 8);
	printf("%d\n", ret);
	ret = printf("test nr: %+-d HEHEH\n", 8);
	printf("%d\n", ret);
	return (0);
}
