/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:59:33 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/25 14:22:29 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	draw_intro(t_data *data)
{
	t_coord	tex;
	t_coord	pos;
	int		color;
	int		st;
	int		y;

	pos.x = (IMAGE_WIDTH / 2) - (TX_SIZE / 2);
	pos.y = (IMAGE_HEIGHT / 2) - (TX_SIZE / 2);
	st = 0;
	while (st < TX_SIZE)
	{
		y = 0;
		while (y < TX_SIZE)
		{
			tex.x = (st * TX_SIZE) / TX_SIZE;
			tex.y = (y * TX_SIZE) / TX_SIZE;
			color = data->start_texture[data->intro.current_frame][TX_SIZE
				* tex.y + tex.x];
			if (color != 0x737373)
				my_mlx_pixel_put_2(data, pos.x + st, pos.y + y, color);
			y++;
		}
		st++;
	}
}

void	render_start_screen(t_data *data)
{
	my_clear_image(data->game->image);
	draw_intro(data);
	mlx_put_image_to_window(data->game->mlx, data->game->mlx_win,
		data->game->image->img, 0, 0);
}

void	init_cat(t_sprite *cat, float x, float y, int type)
{
	cat->pos.x = x + 0.5;
	cat->pos.y = y + 0.5;
	cat->type = type;
	if (type == CAT)
		cat->frame_time = 1.0f / (80.0f / 8);
	else
		cat->frame_time = 1.0f / (600.0f / 13);
	cat->frame = 0;
	cat->current_time = 0;
}

void	init_intro(t_data *data)
{
	data->intro.current_frame = 0;
	data->intro.frame_time = 1.5f;
	data->intro.current_time = 0.0f;
	data->intro.is_intro_active = true;
}

void	init_textures(t_data *data)
{
	load_tex(&data->texture_buffer[NORTH - 1], data, data->t_north);
	load_tex(&data->texture_buffer[SOUTH - 1], data, data->t_south);
	load_tex(&data->texture_buffer[EAST - 1], data, data->t_east);
	load_tex(&data->texture_buffer[WEST - 1], data, data->t_west);
	load_tex(&data->texture_buffer[DOOR - 1], data, "path_to_the_door");
	load_tex(&data->texture_buffer[DOOR2 - 1], data, "path_to_the_door");
	load_tex(&data->finish_texture, data, "textures/finish/0");
	load_set(data->cat_sprite, data, "textures/healthycat/", 8);
	load_set(data->demo_sprite, data, "textures/democat/", 13);
	load_set(data->shrimp_sprite, data, "textures/shrimp/", 11);
	load_set(data->start_texture, data, "textures/start/", 4);
}
