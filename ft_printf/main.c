/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:04:46 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 10:57:02 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

void memaddr_print(void *arr)
{
	long long ptr;
	ptr = (long long) &arr;
	ft_putaddr(ptr);
	printf("\n%p\n", &arr);
}

int	main(void)
{
	int	a = 514214125;
	int	b;
	char *c = "Teaast";
	void *d = c;
/* 	a = ft_printf("test % d\n", 5);
	b = printf("test % d\n", 5);
	printf("a: %d b: %d\n", a, b);
	printf("%p\n", &c);
	ft_put_llong_nbr((long long) &c);
	printf("\n");*/
	printf("%p\n", &c);
	ft_putaddr((long long) &c);
	printf("\n");
	memaddr_print(&d);
	printf("\n");
	printf("%lld\n", (long long) &c);

	
	
	return (0);
}

void print_addr(void *arr)
{
	printf("%p", &arr);
}