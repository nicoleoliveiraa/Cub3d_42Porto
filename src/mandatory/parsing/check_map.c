/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:10:40 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/20 12:38:47 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	map_rect_construction(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->map_inf->map_rect = ft_calloc(data->map_inf->height + 1, \
	sizeof(char *));
	if (!data->map_inf->map_rect)
		deal_with_error(data, "Malloc error!");
	while (i <= data->map_inf->height - 1)
	{
		data->map_inf->map_rect[i] = ft_calloc(data->map_inf->width + 1, \
		sizeof(char));
		j = 0;
		while (j < data->map_inf->width)
		{
			if (j < (int)ft_strlen(data->map[i]))
				data->map_inf->map_rect[i][j] = data->map[i][j];
			else
				data->map_inf->map_rect[i][j] = ' ';
			j++;
		}
		data->map_inf->map_rect[i][j] = '\0';
		i++;
	}
	data->map_inf->map_rect[i] = NULL;
}

void	floodfill(t_data *data, char **map_dup, int x, int y)
{
	if (map_dup[y][x] == '1')
		return ;
	if (map_dup[y][x] == '\0' || map_dup[y][x] == 32 || y == 0 \
		|| x == 0 || y == data->map_inf->height - 1)
	{
		ptr_free(map_dup);
		deal_with_error(data, "Map isn't surrounded by walls!");
	}
	map_dup[y][x] = '1';
	floodfill(data, map_dup, x + 1, y);
	floodfill(data, map_dup, x - 1, y);
	floodfill(data, map_dup, x, y + 1);
	floodfill(data, map_dup, x, y - 1);
}

bool	look_for_zero(t_data *data, char **map_dup)
{
	int	i;
	int	j;

	i = 0;
	while (map_dup[i])
	{
		j = 0;
		while (map_dup[i][j])
		{
			if (map_dup[i][j] == '0' || map_dup[i][j] == 'N' \
				|| map_dup[i][j] == 'W' || map_dup[i][j] == 'E' \
				|| map_dup[i][j] == 'S')
			{
				floodfill(data, map_dup, j, i);
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

void	map_is_closed(t_data *data)
{
	char	**map_dup;
	int		i;

	i = 0;
	map_dup = malloc(sizeof(char *) * (data->map_inf->height + 1));
	if (!map_dup)
		deal_with_error(data, "Malloc error!");
	while (data->map_inf->map_rect[i])
	{
		map_dup[i] = ft_strdup(data->map_inf->map_rect[i]);
		i++;
	}
	map_dup[i] = NULL;
	while (1)
	{
		if (!look_for_zero(data, map_dup))
			break ;
	}
	ptr_free(map_dup);
}

void	validate_map(t_data *data)
{
	map_rect_construction(data);
	map_is_closed(data);
}
