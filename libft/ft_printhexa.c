/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:09:01 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/03/07 18:56:27 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_getadresslw(unsigned int num, int *c)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (num >= 16)
	{
		ft_getadresslw(num / 16, c);
		num = num % 16;
	}
	write(1, &hexa[num], 1);
	*c += 1;
}

static void	ft_getadressup(unsigned int num, int *c)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (num >= 16)
	{
		ft_getadressup(num / 16, c);
		num = num % 16;
	}
	write(1, &hexa[num], 1);
	*c += 1;
}

void	ft_printhexa(unsigned int num, const char *type, int *c)
{
	if (num == 0)
	{
		write(1, "0", 1);
		*c += 1;
		return ;
	}
	if (*type == 'X')
	{
		ft_getadressup(num, c);
		return ;
	}
	if (*type == 'x')
	{
		ft_getadresslw(num, c);
		return ;
	}
}
