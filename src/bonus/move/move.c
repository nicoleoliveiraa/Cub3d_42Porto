/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:54:29 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/24 12:43:46 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	handle_movement(float *x, float *y, float cos, float sin)
{
	t_data	*data;

	data = get_data();
	if (data->game->key_w == true)
	{
		*x += cos;
		*y += sin;
	}
	if (data->game->key_s == true)
	{
		*x -= cos;
		*y -= sin;
	}
	if (data->game->key_a == true)
	{
		*x += sin;
		*y -= cos;
	}
	if (data->game->key_d == true)
	{
		*x -= sin;
		*y += cos;
	}
}

void	mouse_rotation(t_data *data)
{
	int	x;
	int	y;
	int	delta_x;

	if (data->game->mouse == false)
		return ;
	mlx_mouse_get_pos(data->game->mlx, data->game->mlx_win, &x, &y);
	delta_x = x - IMAGE_WIDTH / 2;
	if (delta_x > 0)
		data->map_inf->p_direction += ROTATION_SPEED;
	if (delta_x < 0)
		data->map_inf->p_direction -= ROTATION_SPEED;
	mlx_mouse_move(data->game->mlx, data->game->mlx_win, IMAGE_WIDTH / 2, \
	IMAGE_HEIGHT / 2);
}

void	handle_rotation(t_data *data)
{
	mouse_rotation(data);
	if (data->game->key_left == true)
		data->map_inf->p_direction -= ROTATION_SPEED;
	if (data->game->key_right == true)
		data->map_inf->p_direction += ROTATION_SPEED;
	data->map_inf->p_direction = fmod(data->map_inf->p_direction, 2 * PI);
	if (data->map_inf->p_direction < 0)
		data->map_inf->p_direction += 2 * PI;
}

void	render_game(t_data *data)
{
	my_clear_image(data->game->image);
	raycasting(data);
	put_minimap(data->game->image);
	mlx_put_image_to_window(data->game->mlx, data->game->mlx_win,
		data->game->image->img, 0, 0);
}

int	move(t_data *data)
{
	float	move_cos;
	float	move_sin;
	float	new_x;
	float	new_y;

	move_cos = cos(data->map_inf->p_direction) * MOVE_SPEED;
	move_sin = sin(data->map_inf->p_direction) * MOVE_SPEED;
	new_x = data->map_inf->p_position->x;
	new_y = data->map_inf->p_position->y;
	handle_movement(&new_x, &new_y, move_cos, move_sin);
	update_position(data, new_x, new_y);
	handle_rotation(data);
	render_game(data);
	return (0);
}
