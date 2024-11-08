/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:28:22 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	check_collision(t_data *data, float new_x, float new_y)
{
	int		tile_x;
	int		tile_y;
	int		tile_x_end;
	int		tile_y_end;
	char	**map;

	tile_x = new_x;
	tile_y = new_y;
	tile_x_end = new_x;
	tile_y_end = new_y;
	map = data->map_inf->map_rect;
	if (map[tile_y][tile_x] == '1'
		|| map[tile_y][tile_x_end] == '1'
		|| map[tile_y_end][tile_x] == '1'
		|| map[tile_y_end][tile_x_end] == '1')
		return (1);
	if (map[tile_y][tile_x] == 'C'
		|| map[tile_y][tile_x_end] == 'C'
		|| map[tile_y_end][tile_x] == 'C'
		|| map[tile_y_end][tile_x_end] == 'C')
		return (1);
	return (0);
}

void	update_position(t_data *data, float new_x, float new_y)
{
	if (!check_collision(data, data->map_inf->p_position->x, new_y))
		data->map_inf->p_position->y = new_y;
	if (!check_collision(data, new_x, data->map_inf->p_position->y))
		data->map_inf->p_position->x = new_x;
}
