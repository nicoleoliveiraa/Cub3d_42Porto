/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:47:57 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/03/12 16:11:05 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		res[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
/* #include <stdio.h>

int main(void)
{
	char const *s1 = "aaa";
	char const *s2 = "bbb";
	
	printf("%s", ft_strjoin(s1, s2));
} */