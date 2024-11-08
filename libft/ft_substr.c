/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:53:30 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/09 16:05:07 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	size_t			i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
/* 
#include <stdio.h>

int main(void)
{
	char const *s = "hola";
	printf("%s", ft_substr(s, 0, 18446744073709551615));
}  */