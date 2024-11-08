/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:12:38 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/20 12:38:47 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

bool	is_space(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (true);
	return (false);
}

int	move_space(char *src, int i)
{
	while (src[i] && is_space(src[i]))
		i++;
	return (i);
}

bool	is_empty_line(char *src, int j)
{
	int	i;

	i = 0;
	while (src[i] && i < j)
	{
		if (!is_space(src[i]) && src[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

int	split_size(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
		i++;
	return (i);
}

bool	check_quotes(char *str)
{
	int	i;
	int	quotes;

	quotes = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			quotes++;
		i++;
	}
	if (quotes == 2)
		return (true);
	return (false);
}
