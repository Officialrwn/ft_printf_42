/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:22:44 by leo               #+#    #+#             */
/*   Updated: 2022/02/08 03:09:14 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Cast the parameter to ((long long) &llnum) 
** when calling the function to retrieve the 
** memory address as LLONG and convert to 0x.
*/

void	ft_putaddr(long long llnum)
{
	char		*mem_addr;

	mem_addr = ft_itoa_base(llnum, 16);
	ft_putstr("0x");
	ft_putstr(mem_addr);
}
