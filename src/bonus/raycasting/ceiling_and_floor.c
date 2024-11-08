/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:15:28 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	ceiling_shadow(t_ray *ray, int *color)
{
	int		r;
	int		g;
	int		b;
	float	shadow;

	if (ray->wall_dist <= 1.0)
		return ;
	if (ray->draw.i <= IMAGE_HEIGHT / 6 * 2)
		return ;
	shadow = 1.0 - (float)(ray->draw.i) / (IMAGE_HEIGHT / 4) * 0.000005;
	r = (*color >> 16) & 0xFF;
	g = (*color >> 8) & 0xFF;
	b = *color & 0xFF;
	r = (int)(r * shadow);
	g = (int)(g * shadow);
	b = (int)(b * shadow);
	*color = (r << 16) | (g << 8) | b;
}

void	floor_shadow(t_ray *ray, int *color, int i)
{
	int		r;
	int		g;
	int		b;
	float	shadow;

	if (ray->wall_dist <= 1.0)
		return ;
	if (i >= IMAGE_HEIGHT / 6 * 4)
		return ;
	shadow = 1.0 - (float)(i) / (IMAGE_HEIGHT / 4) * 0.000005;
	r = (*color >> 16) & 0xFF;
	g = (*color >> 8) & 0xFF;
	b = *color & 0xFF;
	r = (int)(r * shadow);
	g = (int)(g * shadow);
	b = (int)(b * shadow);
	*color = (r << 16) | (g << 8) | b;
}

void	draw_floor(int y, t_ray *ray, char *color)
{
	int		clr;
	t_data	*data;

	clr = rgb_to_int(color);
	data = get_data();
	while (y >= ray->draw.end)
	{
		floor_shadow(ray, &clr, y);
		my_mlx_pixel_put(data->game->image, ray->ray_nbr, y, clr);
		y--;
	}
}

void	draw_ceiling(int y, t_ray *ray, char *color)
{
	int		clr;
	t_data	*data;

	clr = rgb_to_int(color);
	data = get_data();
	while (ray->draw.i < y)
	{
		ceiling_shadow(ray, &clr);
		my_mlx_pixel_put(data->game->image, ray->ray_nbr, ray->draw.i, clr);
		ray->draw.i++;
	}
}
