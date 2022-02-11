/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:23:30 by leo               #+#    #+#             */
/*   Updated: 2022/02/11 10:32:43 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define FLAGS "0# -+"
#define UINTFLAGS 
typedef enum e_flags
{
	ZERO = 1,
	HASH = 2,
	SPACE = 4,
	HYPHEN = 8,
	PLUS = 16,
	FLAGNULL = 0
}	t_flags;

int main(void)
{
	t_flags flag[2];
	flag[0] = 1 << 3;
	flag[1] = 1 << 1;
	printf("%d\n", flag[0]);
	printf("%d\n", flag[1]);
	if (flag[0] == HYPHEN)
		printf("True");
	else
		printf("False");
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