/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:57:45 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/09 11:09:22 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	littlelen;

	i = 0;
	littlelen = ft_strlen(little);
	if (littlelen == 0)
		return ((char *)big);
	while (big[i] != '\0' && i <= len - littlelen && littlelen <= len)
	{
		if (big[i] == little[0])
			if (ft_memcmp(big + i, little, littlelen) == 0)
				return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/* #include <stdio.h>
int main(void)
{
	const char *a = "aaabbbbaaaa";
	const char *b = "bbbb";

	printf("%s\n", ft_strnstr(a, b, 7));
}  */