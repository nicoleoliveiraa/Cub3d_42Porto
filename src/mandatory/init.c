/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:28:19 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/20 13:42:49 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_game(t_data *data)
{
	t_game	*game;

	game = data->game;
	game->map = data->map_inf;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, IMAGE_WIDTH, IMAGE_HEIGHT, \
	"Cub3d");
	game->image = calloc(1, sizeof(t_image));
	game->image->height = IMAGE_HEIGHT;
	game->image->width = IMAGE_WIDTH;
	game->image->img = mlx_new_image(game->mlx, game->image->width, \
	game->image->height);
	game->image->addr = mlx_get_data_addr(game->image->img, \
	&game->image->bits_per_pixel, &game->image->line_length, \
	&game->image->endian);
	game->map->square_length = 10;
	game->map->m_position->x = game->map->p_position->x * TILESIZE + \
	TILESIZE / 2;
	game->map->m_position->y = game->map->p_position->y * TILESIZE + \
	TILESIZE / 2;
	data->map_inf->p_direction = get_direction(data);
	init_textures(data);
}

void	init_data(t_data *data)
{
	data->map_inf = ft_calloc(1, sizeof(t_map));
	data->map_inf->p_position = ft_calloc(1, sizeof(t_pos));
	data->map_inf->m_position = ft_calloc(1, sizeof(t_pos));
	data->game = ft_calloc(1, sizeof(t_game));
}

void	game_loop(t_data *data)
{
	t_game	*game;

	game = data->game;
	mlx_hook(game->mlx_win, K_PRESS, K_PRESS_MASK, key_press, game);
	mlx_hook(game->mlx_win, K_RELEASE, K_RELEASE_MASK, key_release, game);
	mlx_hook(game->mlx_win, DESTROY, 0, close_window, NULL);
	mlx_loop_hook(data->game->mlx, move, data);
	mlx_loop(data->game->mlx);
}
