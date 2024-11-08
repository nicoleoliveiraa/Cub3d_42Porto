/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:16:29 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/20 12:37:47 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

float	get_direction(t_data *data)
{
	if (data->map_inf->p_orientation == 'N')
		return ((float)(3 * PI / 2));
	else if (data->map_inf->p_orientation == 'S')
		return ((float)(PI / 2));
	else if (data->map_inf->p_orientation == 'E')
		return (0.0f);
	return (PI);
}

void	open_close_door(void)
{
	t_data	*data;
	int		tile_x_end;
	int		tile_y_end;
	char	**map;
	t_map	*map_inf;

	data = get_data();
	map_inf = data->map_inf;
	tile_x_end = map_inf->p_position->x + \
	cos(map_inf->p_direction) * 0.3;
	tile_y_end = map_inf->p_position->y + \
	sin(map_inf->p_direction) * 0.3;
	map = map_inf->map_rect;
	if (map[tile_y_end][tile_x_end] == 'C')
		map[tile_y_end][tile_x_end] = 'O';
	else if (map[tile_y_end][tile_x_end] == 'O' && \
		map[(int)map_inf->p_position->y][(int)map_inf->p_position->x] != \
		map[tile_y_end][tile_x_end])
		map[tile_y_end][tile_x_end] = 'C';
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == Z)
		game->mouse = false;
	if (keycode == A)
		game->key_a = true;
	if (keycode == S)
		game->key_s = true;
	if (keycode == D)
		game->key_d = true;
	if (keycode == W)
		game->key_w = true;
	if (keycode == E || keycode == M)
		open_close_door();
	if (keycode == LEFT)
		game->key_left = true;
	if (keycode == RIGHT)
		game->key_right = true;
	if (keycode == ESC)
		close_window();
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == A)
		game->key_a = false;
	if (keycode == S)
		game->key_s = false;
	if (keycode == D)
		game->key_d = false;
	if (keycode == W)
		game->key_w = false;
	if (keycode == LEFT)
		game->key_left = false;
	if (keycode == RIGHT)
		game->key_right = false;
	return (0);
}

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
