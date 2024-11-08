/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:19:39 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	set_cat(t_coord pos, int index, int type, float time)
{
	t_game	*game;

	game = get_data()->game;
	game->cats[index].pos.x = pos.x + 0.5;
	game->cats[index].pos.y = pos.y + 0.5;
	game->cats[index].type = type;
	game->cats[index].frame = 0;
	game->cats[index].frame_time = time;
	game->cats[index].current_time = 0;
}

void	assign_cat_type(t_game *game, int x, int y, int *index)
{
	char	tile;

	tile = game->map->map_rect[y][x];
	if (tile == 'F')
	{
		set_cat((t_coord){x, y}, *index, CAT, 1.0f / (80.0f / 8));
		(*index)++;
	}
	else if (tile == 'D')
	{
		set_cat((t_coord){x, y}, *index, DEMO, 1.0f / (600.0f / 13));
		(*index)++;
	}
}

void	init_cat_positions(t_game *game, int *index)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			assign_cat_type(game, x, y, index);
			x++;
		}
		y++;
	}
}

void	check_collectables(t_game *game, char **matrix, int x, int y)
{
	if (matrix[y][x] == '1')
		return ;
	if (matrix[y][x] == 'D')
		game->colectables++;
	matrix[y][x] = '1';
	check_collectables(game, matrix, x + 1, y);
	check_collectables(game, matrix, x - 1, y);
	check_collectables(game, matrix, x, y + 1);
	check_collectables(game, matrix, x, y - 1);
}

void	check_path(t_data *data)
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
	check_collectables(data->game, map_dup, (int)data->map_inf->p_position->x, \
		(int)data->map_inf->p_position->y);
	ptr_free(map_dup);
	if (data->game->colectables != data->game->demo_cats)
		deal_with_error(data, "Map contains unreachable demo cats!");
}
