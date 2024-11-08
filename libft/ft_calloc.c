/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:27:21 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/09 11:47:37 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}

/* int main (void)
{
	char *str;
    int tamanho = 5;

	str = (char *)ft_calloc(tamanho, sizeof(char));
	printf("%s\n", str);
} */
