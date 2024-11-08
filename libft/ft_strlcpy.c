/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:32:47 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/07 13:50:54 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size -1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
	char source[] = "Hello world!";
	char destination[10];
	size_t length = ft_strlcpy(destination, source, 10);

	printf("%zu\n", length);
	printf("%s\n", destination);
} */