/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:33:50 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 14:10:30 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	*get_texture(t_ray *ray)
{
	if (ray->side == NORTH)
		return (get_data()->texture_buffer[0]);
	else if (ray->side == SOUTH)
		return (get_data()->texture_buffer[1]);
	else if (ray->side == EAST)
		return (get_data()->texture_buffer[2]);
	else if (ray->side == WEST)
		return (get_data()->texture_buffer[3]);
	return (NULL);
}

void	load_textures(t_data *data, int tx_i, char *path)
{
	int		width;
	int		height;
	t_image	img;
	int		i;
	int		j;

	img.img = mlx_xpm_file_to_image(data->game->mlx, path, &width, &height);
	if (!img.img)
		return ;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	data->texture_buffer[tx_i] = malloc(sizeof(int) \
				* (TX_SIZE * TX_SIZE));
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			data->texture_buffer[tx_i][j * width + i] = \
			((int *)img.addr)[j * (img.line_length / 4) + i];
	}
	mlx_destroy_image(data->game->mlx, img.img);
}

void	init_textures(t_data *data)
{
	load_textures(data, NORTH - 1, data->t_north);
	load_textures(data, SOUTH - 1, data->t_south);
	load_textures(data, EAST - 1, data->t_east);
	load_textures(data, WEST -1, data->t_west);
}

double	calculate_tex_pos(t_ray *ray, double step)
{
	return ((ray->draw.start - IMAGE_HEIGHT / 2 + \
			ray->draw.line_height / 2) * step);
}
