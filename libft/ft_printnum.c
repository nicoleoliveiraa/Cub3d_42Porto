/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:18:44 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/03/07 18:56:32 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnum(int num, int *c)
{
	if (num == -2147483648)
	{
		*c += write(1, "-2147483648", 11);
	}
	else
	{
		if (num < 0)
		{
			num = -num;
			*c += write(1, "-", 1);
		}
		while (num >= 10)
		{
			ft_printnum(num / 10, c);
			num = num % 10;
		}
		ft_printchar(num + '0', c);
	}
}
