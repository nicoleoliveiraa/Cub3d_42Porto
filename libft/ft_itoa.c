/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:09:50 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/10 11:44:56 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int nbr)
{
	int	c;

	c = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		c++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		c++;
	}
	return (c);
}

static char	*ft_iszero(char	*str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	nb;
	char		*str;

	nb = n;
	i = ft_len(nb);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		return (ft_iszero(str));
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	str[i] = '\0';
	while (nb > 0)
	{
		str[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

/* #include <stdio.h>
int main(void)
{
	int nbr;
	char *str;

	nbr = -7464;
	str = ft_itoa(nbr);
	printf("%s\n", str);
	return (0);
}  */