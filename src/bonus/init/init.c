/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:54:46 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	init_shrimp(t_game *game)
{
	game->shrimp.frame_time = 1.0f / (300.0f / 10);
	game->shrimp.pos.x = IMAGE_WIDTH / 2 - TX_SIZE / 2;
	game->shrimp.pos.y = IMAGE_HEIGHT - TX_SIZE;
}

void	init_image(t_game *game)
{
	game->image = calloc(1, sizeof(t_image));
	game->image->height = IMAGE_HEIGHT;
	game->image->width = IMAGE_WIDTH;
	game->image->img = mlx_new_image(game->mlx, game->image->width, \
			game->image->height);
	game->image->addr = mlx_get_data_addr(game->image->img, \
		&game->image->bits_per_pixel, &game->image->line_length, \
		&game->image->endian);
}

void	init_cats(t_game *game)
{
	int		index;
	t_coord	pos;

	index = 0;
	pos.y = 0;
	game->cats = malloc(game->nbr_cats * sizeof(t_sprite));
	while (pos.y < game->map->height)
	{
		pos.x = 0;
		while (pos.x < game->map->width)
		{
			if (game->map->map_rect[pos.y][pos.x] == 'F')
			{
				init_cat(&game->cats[index], pos.x, pos.y, CAT);
				index++;
			}
			else if (game->map->map_rect[pos.y][pos.x] == 'D')
			{
				init_cat(&game->cats[index], pos.x, pos.y, DEMO);
				index++;
			}
			pos.x++;
		}
		pos.y++;
	}
}

int	init_mouse(t_game *game)
{
	game->mouse = true;
	mlx_mouse_move(game->mlx, game->mlx_win, IMAGE_WIDTH / 2, \
	IMAGE_HEIGHT / 2);
	return (0);
}
