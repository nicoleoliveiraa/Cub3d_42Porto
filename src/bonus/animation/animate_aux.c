/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:44:58 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	set_sprite_drawing_bounds(t_sprite *sprite)
{
	sprite->draw_start.y = -sprite->height / 2 + IMAGE_HEIGHT / 2;
	if (sprite->draw_start.y < 0)
		sprite->draw_start.y = 0;
	sprite->draw_end.y = sprite->height / 2 + IMAGE_HEIGHT / 2;
	if (sprite->draw_end.y >= IMAGE_HEIGHT)
		sprite->draw_end.y = IMAGE_HEIGHT - 1;
	sprite->draw_start.x = -sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_start.x < 0)
		sprite->draw_start.x = 0;
	sprite->draw_end.x = sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_end.x >= IMAGE_WIDTH)
		sprite->draw_end.x = IMAGE_WIDTH - 1;
}

void	set_sprite_dimensions(t_sprite *sprite)
{
	sprite->height = (int)(IMAGE_HEIGHT / sprite->transform.y);
	sprite->width = sprite->height;
}

void	set_sprite_transform(t_data *data, t_ray *ray, t_sprite *sprite)
{
	float	x;
	float	y;
	float	inv_det;

	x = sprite->pos.x - data->map_inf->p_position->x;
	y = sprite->pos.y - data->map_inf->p_position->y;
	inv_det = 1.0 / (ray->pl_dir.x * ray->dir.y - ray->dir.x * ray->pl_dir.y);
	sprite->transform.x = inv_det * (ray->dir.y * x - ray->dir.x * y);
	sprite->transform.y = inv_det * (-ray->pl_dir.y * x + ray->pl_dir.x * y);
	sprite->screen_x = (int)((IMAGE_WIDTH / 2)
			* (1 + sprite->transform.x / sprite->transform.y));
}

void	set_distances(t_data *data, t_ray *ray, t_sprite *sprites, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		set_sprite_transform(data, ray, &sprites[i]);
		set_sprite_dimensions(&sprites[i]);
		set_sprite_drawing_bounds(&sprites[i]);
	}
}
