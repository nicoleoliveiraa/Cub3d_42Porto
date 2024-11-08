/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:38:20 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/14 17:03:39 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}
/* 
int main(void)
{
	const char *s1 = "aaaa";
	const char *s2 = "aada";
	int result = memcmp(s1, s2, 3); 
    printf("%d\n", result);    
    int result2 = ft_memcmp(s1, s2, 3); 
    printf("%d\n", result2);
} */