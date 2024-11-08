/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:33:50 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/25 14:22:25 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

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
	else if (ray->side == DOOR)
		return (get_data()->texture_buffer[DOOR - 1]);
	else if (ray->side == DOOR2)
		return (get_data()->texture_buffer[DOOR2 - 1]);
	return (NULL);
}

void	load_tex(int **dest, t_data *data, char *path)
{
	t_image	img;
	int		i;
	int		j;

	img.img = mlx_xpm_file_to_image(data->game->mlx, path, &img.width, \
		&img.height);
	if (!img.img)
		return ;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	*dest = malloc(sizeof(int) * (TX_SIZE * TX_SIZE));
	i = 0;
	while (i < img.height)
	{
		j = 0;
		while (j < img.width)
		{
			(*dest)[j * img.width + i] = ((int *)img.addr)[j
				* (img.line_length / 4) + i];
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->game->mlx, img.img);
}

void	build_texture_path(char *base_path, int index, char *full_path)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (base_path[i])
		full_path[len++] = base_path[i++];
	if (index >= 10)
		full_path[len++] = '1';
	full_path[len++] = (index % 10) + '0';
	full_path[len++] = '\0';
}

void	load_set(int **textures, t_data *data, char *base_path, int n_textures)
{
	char	full_path[50];
	int		i;

	i = 0;
	while (i < n_textures)
	{
		build_texture_path(base_path, i, full_path);
		load_tex(&textures[i], data, full_path);
		i++;
	}
}

double	calculate_tex_pos(t_ray *ray, double step)
{
	return ((ray->draw.start - IMAGE_HEIGHT / 2 + \
			ray->draw.line_height / 2) * step);
}
