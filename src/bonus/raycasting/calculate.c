/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:50:48 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	calculate_distance(t_ray *ray, t_data *data)
{
	if (ray->side == NORTH || ray->side == SOUTH || ray->side == DOOR)
		ray->wall_dist = (ray->mapx - data->map_inf->p_position->x + \
		(1 - ray->stepx) / 2) / ray->ray_dir.x;
	else if (ray->side == EAST || ray->side == WEST || ray->side == DOOR2)
		ray->wall_dist = (ray->mapy - data->map_inf->p_position->y + \
		(1 - ray->stepy) / 2) / ray->ray_dir.y;
	ray->w_distance[ray->ray_nbr] = ray->wall_dist;
}

void	is_a_door(t_ray *ray)
{
	ray->hit = true;
	if (ray->side == 0)
	{
		if (ray->ray_dir.x < 0)
			ray->side = 5;
		else if (ray->ray_dir.x > 0)
			ray->side = 5;
	}
	else if (ray->side == 1)
	{
		if (ray->ray_dir.y < 0)
			ray->side = 6;
		else if (ray->ray_dir.y > 0)
			ray->side = 6;
	}
}

void	check_next_step(t_ray *ray, t_data *data)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->dist.x;
		ray->mapx += ray->stepx;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->dist.y;
		ray->mapy += ray->stepy;
		ray->side = 1;
	}
	if (data->map_inf->map_rect[ray->mapy][ray->mapx] == 'C')
		is_a_door(ray);
	if (data->map_inf->map_rect[ray->mapy][ray->mapx] == '1')
		which_side(ray);
}

void	find_side(t_ray *ray, t_data *data)
{
	ray->hit = false;
	ray->side = 0;
	while (!ray->hit)
		check_next_step(ray, data);
	calculate_distance(ray, data);
}

void	calculate_dda(t_ray *ray, t_data *data)
{
	step_and_distance(ray, data);
	find_side(ray, data);
}
