/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:42:22 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/07 13:43:04 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/* 
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int c = 3;

	printf("%d\n", ft_tolower(c));
	printf("%d\n", tolower(c));
} */