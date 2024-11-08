/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:47:16 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < image->width && y >= 0 && y < image->height)
	{
		dst = image->addr + (y * image->line_length
				+ x * (image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	my_clear_image(t_image *image)
{
	t_data	*d;

	d = get_data();
	mlx_destroy_image(d->game->mlx, image->img);
	image->img = mlx_new_image(d->game->mlx, image->width, image->height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
}

int	main_loop(t_data *data)
{
	if (data->intro.is_intro_active)
	{
		data->intro.current_time += 0.01f;
		if (data->intro.current_time >= data->intro.frame_time)
		{
			data->intro.current_frame++;
			if (data->intro.current_frame > 3)
			{
				data->intro.current_frame = 0;
				data->intro.is_intro_active = false;
			}
			data->intro.current_time = 0;
		}
		render_start_screen(data);
	}
	else
		move(data);
	return (0);
}

void	game_loop(t_data *data)
{
	t_game	*game;

	game = data->game;
	mlx_hook(game->mlx_win, E_WIN, ENTER_WIN, init_mouse, game);
	mlx_hook(game->mlx_win, K_PRESS, K_PRESS_MASK, key_press, game);
	mlx_hook(game->mlx_win, K_RELEASE, K_RELEASE_MASK, key_release, game);
	mlx_mouse_hook(game->mlx_win, key_press, game);
	mlx_hook(game->mlx_win, DESTROY, 0, close_window, NULL);
	mlx_loop_hook(data->game->mlx, main_loop, data);
	mlx_loop(data->game->mlx);
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
