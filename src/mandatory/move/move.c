/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:54:29 by lebarbos          #+#    #+#             */
/*   Updated: 2024/10/05 12:26:27 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

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

void	update_position(t_data *data, float new_x, float new_y)
{
	if (!check_collision(data, data->map_inf->p_position->x, new_y))
		data->map_inf->p_position->y = new_y;
	if (!check_collision(data, new_x, data->map_inf->p_position->y))
		data->map_inf->p_position->x = new_x;
}

void	handle_rotation(t_data *data)
{
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
