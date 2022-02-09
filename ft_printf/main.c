/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:04:46 by leo               #+#    #+#             */
/*   Updated: 2022/02/09 14:24:25 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	short	a;

	a = 5;
	int ret = ft_printf("test%5555d\n", a);
	//printf("%d\n", ret);
	printf("test: -%-11d-", 3);
		
	return (0);
}
