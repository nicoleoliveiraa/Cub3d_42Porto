/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:55:11 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/25 16:08:44 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	init_ray(t_ray *ray, t_data *data)
{
	ray->ray_pos = 2 * (float)ray->ray_nbr / (float)IMAGE_WIDTH - 1;
	ray->ray_dir.x = ray->dir.x + ray->pl_dir.x * ray->ray_pos;
	ray->ray_dir.y = ray->dir.y + ray->pl_dir.y * ray->ray_pos;
	ray->mapx = (int)data->map_inf->p_position->x;
	ray->mapy = (int)data->map_inf->p_position->y;
	ray->dist.x = fabs(1 / ray->ray_dir.x);
	ray->dist.y = fabs(1 / ray->ray_dir.y);
}

void	get_directions(t_ray *ray, t_data *data)
{
	ray->dir.x = cos(data->map_inf->p_direction);
	ray->dir.y = sin(data->map_inf->p_direction);
	ray->pl_dir.x = -sin(data->map_inf->p_direction) * 0.66;
	ray->pl_dir.y = cos(data->map_inf->p_direction) * 0.66;
}

void	which_side(t_ray *ray)
{
	ray->hit = true;
	if (ray->side == 0)
	{
		if (ray->ray_dir.x < 0)
			ray->side = NORTH;
		else if (ray->ray_dir.x > 0)
			ray->side = SOUTH;
	}
	else if (ray->side == 1)
	{
		if (ray->ray_dir.y < 0)
			ray->side = EAST;
		else if (ray->ray_dir.y > 0)
			ray->side = WEST;
	}
}
