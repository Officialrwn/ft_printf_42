/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_llong_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:54:57 by leotran           #+#    #+#             */
/*   Updated: 2022/02/08 03:17:52 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_llong_nbr(long long llnum)
{
	long long	i;
	int			count;

	i = 1;
	count = 0;
	if (llnum < 0)
	{
		ft_putchar('-');
		llnum *= -1;
	}
	while (i <= (llnum / 10))
	{
		i = i * 10;
		count++;
	}
	while (count > 0)
	{
		ft_putchar((llnum / i) + '0');
		llnum %= i;
		i /= 10;
		count--;
	}
	ft_putchar(llnum + '0');
}
