/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:09:10 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/07 13:47:35 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int main(void)
{
	int c;

	c = 'f';
	printf("%d\n", isascii(c));
	printf("%d\n", ft_isascii(c));
} */