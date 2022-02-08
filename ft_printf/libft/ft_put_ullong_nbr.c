/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ullong_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:54:57 by leotran           #+#    #+#             */
/*   Updated: 2022/02/08 14:34:18 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_ullong_nbr(unsigned long long ullnum)
{
	unsigned long long	num;
	unsigned long long	i;
	int					count;

	num = ullnum;
	i = 1;
	count = 0;
	while (i <= (num / 10))
	{
		i = i * 10;
		count++;
	}
	while (count > 0)
	{
		ft_putchar((num / i) + '0');
		num %= i;
		i /= 10;
		count--;
	}
	ft_putchar(num + '0');
}
