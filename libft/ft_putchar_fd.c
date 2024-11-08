/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:51:15 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/11 13:30:56 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main()
{
	int fd = open("ola.txt", O_WRONLY);

	printf("%d", fd);
	ft_putchar_fd('a', fd);
	ft_putchar_fd('b', 2);
}
*/
