/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:39:16 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/07 17:09:38 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*lastc;

	i = 0;
	lastc = NULL;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			lastc = (char *)&str[i];
		i++;
	}
	if ((unsigned char)str[i] == (unsigned char)c)
		lastc = (char *)&str[i];
	return (lastc);
}
