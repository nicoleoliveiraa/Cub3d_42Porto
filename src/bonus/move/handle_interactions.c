/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_interactions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:41:35 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	handle_cat_interaction(t_data *data, t_coord tile_cat)
{
	char	**map;

	map = data->map_inf->map_rect;
	data->game->shrimp.visible = true;
	data->game->shrimp.current_frame = 0;
	data->game->shrimp.current_time = 0;
	data->game->exorcise_cat_index = -1;
	if (map[(int)tile_cat.y][(int)tile_cat.x] == 'D')
		exorcise((t_coord){tile_cat.x, tile_cat.y});
}

void	handle_door(t_data *data, t_coord tile_door, t_pos pos)
{
	char	**map;

	map = data->map_inf->map_rect;
	if (map[(int)tile_door.y][(int)tile_door.x] == 'C')
		map[(int)tile_door.y][(int)tile_door.x] = 'O';
	else if (map[(int)tile_door.y][(int)tile_door.x] == 'O' && \
		map[(int)pos.y][(int)pos.x] != map[(int)tile_door.y][(int)tile_door.x])
		map[(int)tile_door.y][(int)tile_door.x] = 'C';
}

void	set_tile_positions(t_data *data, t_coord *door, t_coord *cat, t_pos pos)
{
	door->x = pos.x + cos(data->map_inf->p_direction) * 0.3;
	door->y = pos.y + sin(data->map_inf->p_direction) * 0.3;
	cat->x = pos.x + cos(data->map_inf->p_direction) * 1.1;
	cat->y = pos.y + sin(data->map_inf->p_direction) * 1.1;
}

void	set_player_position(t_data *data, t_pos *pos)
{
	pos->x = data->map_inf->p_position->x;
	pos->y = data->map_inf->p_position->y;
}

void	handle_door_and_cats(void)
{
	t_data	*data;
	t_coord	door;
	t_coord	cat;
	t_pos	pos;

	data = get_data();
	set_player_position(data, &pos);
	set_tile_positions(data, &door, &cat, pos);
	if (data->map_inf->map_rect[door.y][door.x] == 'C'
		|| data->map_inf->map_rect[door.y][door.x] == 'O')
		handle_door(data, door, pos);
	else
		handle_cat_interaction(data, cat);
}
