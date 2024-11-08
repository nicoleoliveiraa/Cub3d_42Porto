/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:41:33 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/25 15:44:43 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	get_texture_color(t_ray *ray, int tex_x, int tex_y)
{
	int	*tex_id;

	tex_id = get_texture(ray);
	if (!tex_id)
		return (0x000000);
	if (ray->side < 5)
		return (tex_id[TX_SIZE * tex_y + tex_x]);
	else
		return (0x00008B);
}

int	clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

int	calculate_tex_x(t_data *data, t_ray *ray)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == NORTH || ray->side == SOUTH || ray->side == DOOR)
		wall_x = data->map_inf->p_position->y + ray->wall_dist * ray->ray_dir.y;
	else
		wall_x = data->map_inf->p_position->x + ray->wall_dist * ray->ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * TX_SIZE);
	return (clamp(tex_x, 0, TX_SIZE - 1));
}

void	wall_shadow(t_ray *ray, int *color)
{
	int		r;
	int		g;
	int		b;
	float	shadow;

	if (ray->wall_dist <= 1.0)
		return ;
	shadow = 1 / ray->wall_dist * 1.9;
	if (shadow > 1.0)
		shadow = 1.0;
	r = (*color >> 16) & 0xFF;
	g = (*color >> 8) & 0xFF;
	b = *color & 0xFF;
	r = (int)(r * shadow);
	g = (int)(g * shadow);
	b = (int)(b * shadow);
	*color = (r << 16) | (g << 8) | b;
}

void	draw_wall(t_data *data, t_ray *ray)
{
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;

	tex_x = calculate_tex_x(data, ray);
	step = 1.0 * TX_SIZE / ray->draw.line_height;
	tex_pos = calculate_tex_pos(ray, step);
	ray->draw.i = ray->draw.start;
	while (ray->draw.i < ray->draw.end)
	{
		tex_y = (int)tex_pos & (TX_SIZE - 1);
		tex_y = clamp(tex_y, 0, TX_SIZE - 1);
		tex_pos += step;
		color = get_texture_color(ray, tex_x, tex_y);
		wall_shadow(ray, &color);
		my_mlx_pixel_put_2(data, ray->ray_nbr, ray->draw.i, color);
		ray->draw.i++;
	}
}
