/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:09:01 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/09 11:44:47 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/* int main(void)
{
	char str[] = "aa";
	char str1[] = "aa";
	
	ft_bzero(str, 2);
	printf("%s\n", str);
	bzero(str1, 2);
	printf("%s\n", str1);
} */