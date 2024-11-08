/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:59:25 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/03/07 18:56:43 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printuns(unsigned int num, int *c)
{
	while (num >= 10)
	{
		ft_printnum(num / 10, c);
		num = num % 10;
	}
	ft_printchar(num + '0', c);
}
