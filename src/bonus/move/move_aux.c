/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:16:29 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

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

void	draw_shrimp(t_data *data)
{
	t_shrimp	*shrimp;
	t_coord		tex;
	int			color;
	int			st;
	int			y;

	shrimp = &data->game->shrimp;
	if (!shrimp->visible)
		return ;
	st = shrimp->pos.x;
	while (st < shrimp->pos.x + TX_SIZE)
	{
		tex.x = (st - shrimp->pos.x) * TX_SIZE / TX_SIZE;
		y = shrimp->pos.y;
		while (y < shrimp->pos.y + TX_SIZE)
		{
			tex.y = (y - shrimp->pos.y) * TX_SIZE / TX_SIZE;
			color = data->shrimp_sprite[shrimp->current_frame] \
			[TX_SIZE * tex.y + tex.x];
			if (color != 0x969596)
				my_mlx_pixel_put_2(data, st, y, color);
			y++;
		}
		st++;
	}
}

void	exorcise(t_coord location)
{
	t_game	*game;
	int		i;

	game = get_data()->game;
	i = 0;
	while (i < game->nbr_cats)
	{
		if ((int)game->cats[i].pos.x == location.x
			&& (int)game->cats[i].pos.y == location.y)
			break ;
		i++;
	}
	game->exorcise_cat_index = i;
	game->cats[i].frame_time = 1.0f / (80.0f / 8);
	game->map->map_rect[location.y][location.x] = 'F';
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
		handle_door_and_cats();
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
