/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:04:46 by leo               #+#    #+#             */
/*   Updated: 2022/02/14 11:48:02 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	unsigned char b = 65;

	a = -5;
	int ret = ft_printf("test nr: %lld HEHEH\n", 2147483650LL);
	printf("%d\n", ret);
	ret = printf("test nr: %lld HEHEH\n", 2147483650LL);
	printf("%d\n", ret);
	return (0);
}
