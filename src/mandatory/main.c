/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:47:16 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/20 13:44:38 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < image->width && y >= 0 && y < image->height)
	{
		dst = image->addr + (y * image->line_length + x * \
		(image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

int	close_window(void)
{
	free_data(get_data());
	exit (0);
	return (0);
}

void	my_clear_image(t_image *image)
{
	mlx_destroy_image(get_data()->game->mlx, image->img);
	image->img = mlx_new_image(get_data()->game->mlx, image->width, \
	image->height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
	&image->line_length, &image->endian);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = get_data();
	init_data(data);
	check_scene_description(argc, argv, data);
	init_game(data);
	game_loop(data);
	free_data(data);
}
