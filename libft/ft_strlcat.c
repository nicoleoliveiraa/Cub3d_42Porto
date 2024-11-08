/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:21:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/07 17:37:19 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstlen >= size)
		return (srclen + size);
	while (src[i] != '\0' && (i + dstlen) < (size - 1))
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	return (dstlen + srclen);
}

/* #include <stdio.h>
int main(void)
{
	char source[] = " world!";
	char destination[] = "hello";
	size_t size = 0;

	printf("%zu\n", ft_strlcat(destination, source, size));
	printf("%s\n", destination);
} */