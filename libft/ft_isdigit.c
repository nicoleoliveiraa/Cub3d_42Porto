/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:08:55 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/07 13:47:49 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main(void)
{
	int r;
	int c = '0';

	r = isdigit(c);
	printf("%d\n", r);
	printf("%d\n", ft_isdigit(c));
	return (0);
} */