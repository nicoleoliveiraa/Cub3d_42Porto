/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:30:13 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/25 16:08:49 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

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

void	handle_post_raycast(t_data *data, t_ray *ray)
{
	if (data->game_over)
		finish_game(data);
	draw_shrimp(data);
	update_shrimp(data->game);
	update_cats(data->game->cats, data->game->nbr_cats);
	draw_sprites(data, ray, data->game->cats, data->game->nbr_cats);
}

void	draw_raycast(t_data *data, t_ray *ray)
{
	draw_view(data, ray);
	if (ray->ray_nbr % 2 == 0)
		draw_ray_minimap(data, ray);
}

void	raycast_loop(t_data *data, t_ray *ray)
{
	while (ray->ray_nbr < IMAGE_WIDTH)
	{
		init_ray(ray, data);
		calculate_dda(ray, data);
		if (!data->game_over)
			draw_raycast(data, ray);
		ray->ray_nbr++;
	}
}

void	raycasting(t_data *data)
{
	t_ray	ray;

	ray.ray_nbr = 0;
	get_directions(&ray, data);
	raycast_loop(data, &ray);
	handle_post_raycast(data, &ray);
}
