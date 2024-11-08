/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:55:15 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 17:17:10 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	draw_tiles(t_image *image)
{
	t_data	*data;
	t_pos	start;
	t_pos	finish;
	t_pos	pos;
	t_pos	offset;

	data = get_data();
	pos.x = 0;
	pos.y = 0;
	calculate_map_bounds(data, &start, &finish, &offset);
	data->map_inf->m_position->x = (data->map_inf->p_position->x - start.x)
		* TILESIZE;
	data->map_inf->m_position->y = (data->map_inf->p_position->y - start.y)
		* TILESIZE;
	draw_player(image, *data->map_inf->m_position);
	draw_tiles_loop(start, finish, offset, pos);
}

void	draw_player(t_image *image, t_pos player)
{
	int	color;
	int	radius;
	int	y;
	int	x;

	color = 0x0000FF;
	radius = 1;
	y = player.y - radius;
	while (y <= player.y + radius)
	{
		x = player.x - radius;
		while (x <= player.x + radius)
		{
			if ((x - player.x) * (x - player.x) + (y - player.y)
				* (y - player.y) <= radius * radius)
				my_mlx_pixel_put(image, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_map_tile(t_image *image, t_pos coord, int color)
{
	int	limit_x;
	int	limit_y;
	int	coord_x;
	int	coord_y;

	coord_x = (coord.x * TILESIZE) + 1;
	coord_y = (coord.y * TILESIZE) + 1;
	limit_x = coord_x + TILESIZE - 1;
	limit_y = coord_y + TILESIZE - 1;
	while (coord_y < limit_y)
	{
		coord_x = coord.x * TILESIZE + 1;
		while (coord_x < limit_x)
		{
			my_mlx_pixel_put(image, coord_x, coord_y, color);
			coord_x++;
		}
		coord_y++;
	}
}

void	draw_frame(t_image *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINIMAP_H)
	{
		x = 0;
		while (x < MINIMAP_W)
		{
			if (((y >= 0 && y <= 2) || (y >= MINIMAP_H - 4 && y < MINIMAP_H))
				&& y % 2 == 0)
			{
				if (x % 2 == 0)
					my_mlx_pixel_put(image, x, y, 0xFFFFFF);
			}
			else if (((x >= 0 && x <= 2) || (x >= MINIMAP_W - 4
						&& x < MINIMAP_W)) && x % 2 == 0)
			{
				if (y % 2 == 0)
					my_mlx_pixel_put(image, x, y, 0xFFFFFF);
			}
			x++;
		}
		y++;
	}
}

void	put_minimap(t_image *image)
{
	t_game	*game;

	game = get_data()->game;
	if (!get_data()->game_over)
	{
		draw_tiles(image);
		draw_frame(image);
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->img, 0, 0);
	}
}
