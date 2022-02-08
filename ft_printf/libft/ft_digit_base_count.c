/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:58:23 by leotran           #+#    #+#             */
/*   Updated: 2022/02/08 14:00:24 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit_base_count(long long llnum, int base)
{
	int			count;
	long long	n;

	count = 0;
	n = llnum;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}
