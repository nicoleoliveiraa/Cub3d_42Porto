/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_beam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:21:52 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	calculate_signs(t_coord c, t_coord e, t_coord *sign)
{
	if (c.x < e.x)
		sign->x = 1;
	else
		sign->x = -1;
	if (c.y < e.y)
		sign->y = 1;
	else
		sign->y = -1;
}

void	update_line(int *err, t_coord delta, t_coord *c, t_coord sign)
{
	int	err2;

	err2 = *err * 2;
	if (err2 > -delta.y)
	{
		*err -= delta.y;
		c->x += sign.x;
	}
	if (err2 < delta.x)
	{
		*err += delta.x;
		c->y += sign.y;
	}
}

void	draw(t_coord center, t_coord end)
{
	t_coord	delta;
	t_coord	sign;
	t_image	*image;
	int		err;

	image = get_data()->game->image;
	delta.x = abs(center.x - end.x);
	delta.y = abs(center.y - end.y);
	calculate_signs(center, end, &sign);
	err = delta.x - delta.y;
	while (center.x != end.x || center.y != end.y)
	{
		if (center.x <= MINIMAP_W && center.y <= MINIMAP_H)
			my_mlx_pixel_put(image, center.x, center.y, 0xFFFF00);
		update_line(&err, delta, &center, sign);
	}
}

void	draw_ray_minimap(t_data *data, t_ray *ray)
{
	t_coord	p_pos;
	t_coord	ray_end;

	p_pos.x = data->map_inf->m_position->x;
	p_pos.y = data->map_inf->m_position->y;
	ray_end.x = p_pos.x + ((ray->ray_dir.x * ray->wall_dist) * TILESIZE);
	ray_end.y = p_pos.y + ((ray->ray_dir.y * ray->wall_dist) * TILESIZE);
	draw(p_pos, ray_end);
}
