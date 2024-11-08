/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:48:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/07 13:48:43 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	if (!src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] == c)
			return ((unsigned char *)dest + i + 1);
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (NULL);
}

/* int main(void)
{
	const char *source = "Hello, World!";
	char destination[20];
	int stop_char = 'b';

	void *result = ft_memccpy(destination, source, stop_char, 20);

	if (result != NULL) {
		printf("Caractere de parada encontrado: %c\n", *(char *)result);
	} else {
		printf("Caractere de parada não encontrado.\n");
	}

	printf("Destination: %s\n", destination);

	return 0;
} */