/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:09:45 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/09 11:17:07 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
