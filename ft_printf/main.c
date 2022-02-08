/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:04:46 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 13:44:09 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int a = 5;

	int ret = printf("%p\n", &a);
	printf("ret: %d\n", ret);
	ret = ft_printf("%p\n", &a);
	printf("ret: %d\n", ret);

	return (0);
}
