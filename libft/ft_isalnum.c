/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:09:04 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/14 17:01:52 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/* 
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int c = 'a';

	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(c));
	return (0);
} */