/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:04:46 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 15:21:59 by leotran          ###   ########.fr       */
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
	int ret = ft_printf("test nr: %+d HEHEH\n", -8);
	printf("%d\n", ret);
	ret = printf("test nr: %+d HEHEH\n", -8);
	printf("%d\n", ret);
	return (0);
}
