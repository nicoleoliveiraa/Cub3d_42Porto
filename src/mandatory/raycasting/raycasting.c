/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:30:13 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/20 12:43:28 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	get_directions(t_ray *ray, t_data *data)
{
	ray->dir.x = cos(data->map_inf->p_direction);
	ray->dir.y = sin(data->map_inf->p_direction);
	ray->pl_dir.x = -sin(data->map_inf->p_direction) * 0.66;
	ray->pl_dir.y = cos(data->map_inf->p_direction) * 0.66;
}

void	step_and_distance(t_ray *ray, t_data *data)
{
	if (ray->ray_dir.x < 0)
	{
		ray->stepx = -1;
		ray->side_dist.x = (data->map_inf->p_position->x - \
		ray->mapx) * ray->dist.x;
	}
	else
	{
		ray->stepx = 1;
		ray->side_dist.x = (ray->mapx + 1.0 - \
		data->map_inf->p_position->x) * ray->dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->stepy = -1;
		ray->side_dist.y = (data->map_inf->p_position->y - \
		ray->mapy) * ray->dist.y;
	}
	else
	{
		ray->stepy = 1;
		ray->side_dist.y = (ray->mapy + 1.0 - \
		data->map_inf->p_position->y) * ray->dist.y;
	}
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

void	raycasting(t_data *data)
{
	t_ray	ray;

	ray.ray_nbr = 0;
	get_directions(&ray, data);
	while (ray.ray_nbr < IMAGE_WIDTH)
	{
		init_ray(&ray, data);
		calculate_dda(&ray, data);
		draw_view(data, &ray);
		ray.ray_nbr++;
	}
}
