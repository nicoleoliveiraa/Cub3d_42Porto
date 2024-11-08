/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:45:25 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	rgb_to_int(char *color)
{
	int		rgb;
	char	**clr;

	clr = ft_split(color, ',');
	rgb = ft_atoi(clr[0]) << 16 | ft_atoi(clr[1]) << 8 | ft_atoi(clr[2]);
	ptr_free(clr);
	return (rgb);
}

int	get_color(t_ray *ray)
{
	int	color;

	if (ray->side == 1)
		color = 0xFFA07A;
	else if (ray->side == 2)
		color = 0xFF8C00;
	else if (ray->side == 3)
		color = 0xFF4500;
	else if (ray->side == 4)
		color = 0xCC5500;
	else
		color = 0x8E236B;
	return (color);
}

void	my_mlx_pixel_put_2(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		ofsset;

	ofsset = y * data->game->image->line_length + x
		* (data->game->image->bits_per_pixel / 8);
	dst = data->game->image->addr + ofsset;
	*(unsigned int *)dst = color;
}

void	draw_column(int y, t_ray *ray, char *color)
{
	int		clr;
	t_data	*data;

	clr = rgb_to_int(color);
	data = get_data();
	while (ray->draw.i < y)
	{
		my_mlx_pixel_put_2(data, ray->ray_nbr, ray->draw.i, clr);
		ray->draw.i++;
	}
}

void	draw_view(t_data *data, t_ray *ray)
{
	ray->draw.i = 0;
	ray->draw.line_height = (int)(IMAGE_HEIGHT / ray->wall_dist);
	ray->draw.start = -ray->draw.line_height / 2 + IMAGE_HEIGHT / 2;
	if (ray->draw.start < 0)
		ray->draw.start = 0;
	ray->draw.end = ray->draw.line_height / 2 + IMAGE_HEIGHT / 2;
	if (ray->draw.end > IMAGE_HEIGHT)
		ray->draw.end = IMAGE_HEIGHT - 1;
	draw_ceiling(ray->draw.start, ray, data->ceiling_color);
	draw_wall(data, ray);
	draw_floor(IMAGE_HEIGHT, ray, data->floor_color);
}
