/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:23:30 by leo               #+#    #+#             */
/*   Updated: 2022/02/15 08:33:23 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf/libft/libft.h"

int main(void)
{
	char *arr;

	arr = ft_uitoa_base(0, 10, 0);
	printf("arr: %s\n", arr);
	return (0);
}
/* Hashkey algo for flags: #0- +
	char *arr = "0# -+";
	int temp;
	int hashkey;
	for (int i = 0; i < 5; i++)
	{
		hashkey = 1;
		temp = (int)arr[i];
		while (temp > 0)
		{
			if (temp % 10 == 0)
				hashkey *= 1;
			else
				hashkey *= temp % 10;
			temp /= 10;
		}
		hashkey /= 3;
		hashkey %= 10;
		if (hashkey > 5)
			hashkey /= 2;
		if (hashkey == 5)
			hashkey /= 5;
		printf("%c: ", arr[i]);
		printf("%d", hashkey);
		printf(" bitnum: %d\n", 1 << hashkey );
	}
	*/