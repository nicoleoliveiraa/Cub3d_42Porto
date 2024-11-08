/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:08:03 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	calculate_map_bounds(t_data *data, t_pos *s, t_pos *end, t_pos *offset)
{
	t_pos	pos;

	pos = *data->map_inf->p_position;
	s->x = pos.x - (MINIMAP_W / TILESIZE / 2);
	s->y = pos.y - (MINIMAP_H / TILESIZE / 2);
	end->x = pos.x + (MINIMAP_W / TILESIZE / 2);
	end->y = pos.y + (MINIMAP_H / TILESIZE / 2);
	offset->x = (pos.x - (int)pos.x) * TILESIZE;
	offset->y = (pos.y - (int)pos.y) * TILESIZE;
}

int	check_wall(char **map, t_pos start, t_pos pos, int *color)
{
	t_data	*data;

	data = get_data();
	if (start.y + pos.y >= 0 && start.y + pos.y < data->map_inf->height
		&& start.x + pos.x >= 0 && start.x + pos.x < data->map_inf->width)
	{
		if (map[(int)(start.y + pos.y)][(int)(start.x + pos.x)] == '1'
			|| map[(int)(start.y + pos.y)][(int)(start.x + pos.x)] == 'C'
			|| map[(int)(start.y + pos.y)][(int)(start.x + pos.x)] == 'F'
			|| map[(int)(start.y + pos.y)][(int)(start.x + pos.x)] == 'D')
		{
			if (map[(int)(start.y + pos.y)][(int)(start.x + pos.x)] == 'C')
				*color = 0x0000FF;
			else if (map[(int)(start.y + pos.y)][(int)(start.x + pos.x)] == '1')
				*color = 0xFFFFFF;
			else if (map[(int)(start.y + pos.y)][(int)(start.x + pos.x)] == 'F')
				*color = 0x00FF00;
			else if (map[(int)(start.y + pos.y)][(int)(start.x + pos.x)] == 'D')
				*color = 0x8B0000;
			return (1);
		}
	}
	return (0);
}

void	draw_tiles_loop(t_pos s, t_pos end, t_pos offset, t_pos pos)
{
	char	**map;
	t_data	*data;
	int		color;

	data = get_data();
	map = data->map_inf->map_rect;
	while (s.y + pos.y < data->map_inf->height && s.y + pos.y < end.y)
	{
		pos.x = 0;
		while (s.x + pos.x < data->map_inf->width && s.x + pos.x < end.x)
		{
			if (check_wall(map, s, pos, &color))
			{
				draw_map_tile(data->game->image, (t_pos){
					(pos.x * TILESIZE - offset.x) / TILESIZE,
					(pos.y * TILESIZE - offset.y) / TILESIZE},
					color);
			}
			pos.x++;
		}
		pos.y++;
	}
}
