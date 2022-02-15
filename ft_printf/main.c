/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:04:46 by leo               #+#    #+#             */
/*   Updated: 2022/02/15 21:53:20 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int ret;
	
	ret = ft_printf("test nr:0 -%-5o- HEHEH ret: ", 5);
	printf("%d\n", ret);
	ret = printf("test nr:0 -%-5o- HEHEH ret: ", 5);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:1 -%#-8x- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:1 -%#-8x- HEHEH ret: ", 255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:2 -%+4d- HEHEH ret: ", 5);
	printf("%d\n", ret);
	ret = printf("test nr:2 -%+4d- HEHEH ret: ", 5);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:3 -%+-5d- HEHEH ret: ", 5);
	printf("%d\n", ret);
	ret = printf("test nr:3 -%+-5d- HEHEH ret: ", 5);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%-5d- HEHEH ret: ", -5);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-5d- HEHEH ret: ", -5);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%-#5X- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-#5X- HEHEH ret: ", 255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%- 5i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%- 5i- HEHEH ret: ", 255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%08i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%08i- HEHEH ret: ", 255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%#08x- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%#08x- HEHEH ret: ", 255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%+08i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+08i- HEHEH ret: ", 255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -% 08i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -% 08i- HEHEH ret: ", 255);
	printf("%d\n\n", ret);
	
	ret = ft_printf("test nr:4 -% -8i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -% -8i- HEHEH ret: ", 255);
	printf("%d\n\n", ret);	
	
	ret = ft_printf("test nr:4 -%+d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+d- HEHEH ret: ", 255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%+d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+d- HEHEH ret: ", -255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%#X- HEHEH ret: ", 255255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%#X- HEHEH ret: ", 255255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -% d- HEHEH ret: ", 255255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -% d- HEHEH ret: ", 255255);
	printf("%d\n\n", ret);
	
	ret = ft_printf("test nr:4 -% d- HEHEH ret: ", -255255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -% d- HEHEH ret: ", -255255);
	printf("%d\n\n", ret);	

	ret = ft_printf("test nr:4 -% d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -% d- HEHEH ret: ", 255);
	printf("%d\n\n", ret);		

	ret = ft_printf("test nr:4 -%8d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%8d- HEHEH ret: ", 255);
	printf("%d\n\n", ret);		

	ret = ft_printf("test nr:4 -%8d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%8d- HEHEH ret: ", -255);
	printf("%d\n\n", ret);	

	ret = ft_printf("test nr:4 -%-d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%-d- HEHEH ret: ", -255);
	printf("%d\n\n", ret);	

	ret = ft_printf("test nr:4 -%0d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%0d- HEHEH ret: ", -255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%+005d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+005d- HEHEH ret: ", 255);
	printf("%d\n\n", ret);
	
	ret = ft_printf("test nr:4 -%+005d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%+005d- HEHEH ret: ", -255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%d- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%d- HEHEH ret: ", 255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%i- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%i- HEHEH ret: ", 255);
	printf("%d\n\n", ret);
	
	ret = ft_printf("test nr:4 -%d- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%d- HEHEH ret: ", -255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%i- HEHEH ret: ", -255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%i- HEHEH ret: ", -255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%u- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%u- HEHEH ret: ", 255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%o- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%o- HEHEH ret: ", 255);
	printf("%d\n\n", ret);	

	ret = ft_printf("test nr:4 -%x- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%x- HEHEH ret: ", 255);
	printf("%d\n\n", ret);
			
	ret = ft_printf("test nr:4 -%X- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%X- HEHEH ret: ", 255);
	printf("%d\n\n", ret);			
	
	ret = ft_printf("test nr:4 -%x- HEHEH ret: ", 255);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%x- HEHEH ret: ", 255);
	printf("%d\n\n", ret);

	ret = ft_printf("test nr:4 -%s- HEHEH ret: ", "HelloWorld");
	printf("%d\n", ret);
	ret = printf("test nr:4 -%s- HEHEH ret: ", "HelloWorld");
	printf("%d\n\n", ret);	
	
	ret = ft_printf("test nr:4 -%c- HEHEH ret: ", '@');
	printf("%d\n", ret);
	ret = printf("test nr:4 -%c- HEHEH ret: ", '@');
	printf("%d\n\n", ret);
	
	int a = 42;
	ret = ft_printf("test nr:4 -%p- HEHEH ret: ", &a);
	printf("%d\n", ret);
	ret = printf("test nr:4 -%p- HEHEH ret: ", &a);
	printf("%d\n\n", ret);
	
	return (0);
}
