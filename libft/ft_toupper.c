/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:42:48 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/07 13:43:49 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>

int main(void)
{
	int c = 'q';

	printf("%c\n", ft_toupper(c));
	printf("%c\n", toupper(c));
} */