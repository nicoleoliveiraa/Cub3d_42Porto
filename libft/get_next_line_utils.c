/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:44:44 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/05 19:32:14 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_mod(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while ((unsigned char)str[i] != (unsigned char)c && str[i])
		i++;
	if ((unsigned char)c == (unsigned char)str[i])
		return ((char *)(str + i));
	return (NULL);
}

size_t	ft_strlen_mod(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_mod(char *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	new_string = malloc(sizeof(char) * (ft_strlen_mod(s1) + ft_strlen_mod(s2)
				+ 1));
	if (!new_string)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_string[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_string[i + j] = s2[j];
	free(s1);
	new_string[i + j] = '\0';
	return (new_string);
}
