/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:04:46 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 23:56:26 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	unsigned char b = 65;
	short int c = 500;
	a = -5;
	int ret = ft_printf("test nr: -% -5d- HEHEH\n", 255);
	printf("%d\n", ret);
	ret = printf("test nr: -% -5d- HEHEH\n", 255);
	printf("%d\n", ret);
	return (0);
}
