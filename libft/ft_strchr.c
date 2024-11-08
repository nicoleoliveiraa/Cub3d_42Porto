/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:20:20 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/05 19:28:43 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *buffer, int target)
{
	int	i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i])
	{
		if ((unsigned char)buffer[i] == (unsigned char)target)
			return (&buffer[i]);
		i++;
	}
	if ((unsigned char )buffer[i] == (unsigned char)target)
		return (&buffer[i]);
	return (NULL);
}
