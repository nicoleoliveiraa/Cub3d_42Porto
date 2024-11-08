/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:02:00 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/25 16:09:02 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	init_data(t_data *data)
{
	data->map_inf = ft_calloc(1, sizeof(t_map));
	data->map_inf->p_position = ft_calloc(1, sizeof(t_pos));
	data->map_inf->m_position = ft_calloc(1, sizeof(t_pos));
	data->game = ft_calloc(1, sizeof(t_game));
}

void	init_game(t_data *data)
{
	t_game	*game;

	game = data->game;
	game->map = data->map_inf;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, IMAGE_WIDTH,
			IMAGE_HEIGHT, "Cub3d");
	init_image(game);
	game->map->square_length = 10;
	game->map->m_position->x = game->map->p_position->x * \
		TILESIZE + TILESIZE / 2;
	game->map->m_position->y = game->map->p_position->y * \
		TILESIZE + TILESIZE / 2;
	data->map_inf->p_direction = get_direction(data);
	init_shrimp(data->game);
	init_cats(data->game);
	init_textures(data);
	init_intro(data);
}
