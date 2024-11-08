/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:17:35 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/10 14:17:29 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_thesame(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		s;
	char	*strim;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (ft_thesame(s1[i], set) && s1[i])
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_thesame(s1[j], set) && j > 0)
		j--;
	if (j < i)
		return (ft_strdup(""));
	strim = (char *)malloc(sizeof(char) * (j - i + 2));
	if (strim == NULL)
		return (NULL);
	s = 0;
	while (i <= j)
		strim[s++] = s1[i++];
	strim[s] = '\0';
	return (strim);
}
