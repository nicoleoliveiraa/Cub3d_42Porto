/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:18:24 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	draw_sprites(t_data *data, t_ray *ray, t_sprite *cats, int num_cats)
{
	int	i;

	i = -1;
	set_distances(data, ray, cats, num_cats);
	while (++i < num_cats)
	{
		draw_single_sprite(data, ray, &cats[i]);
	}
}

void	draw_single_sprite(t_data *data, t_ray *ray, t_sprite *cat)
{
	int	st;

	st = cat->draw_start.x;
	while (st < cat->draw_end.x)
	{
		if (cat->transform.y > 0 && st >= 0 && st < IMAGE_WIDTH
			&& cat->transform.y < ray->w_distance[st])
			draw_vertical_stripe(data, cat, st);
		st++;
	}
}

void	draw_vertical_stripe(t_data *data, t_sprite *cat, int st)
{
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;

	tex_x = (int)((st - (-cat->width / 2 + cat->screen_x))
			* TX_SIZE / cat->width);
	if (tex_x < 0 || tex_x >= TX_SIZE)
		return ;
	y = cat->draw_start.y;
	while (y < cat->draw_end.y)
	{
		tex_y = (y - IMAGE_HEIGHT / 2 + cat->height / 2)
			* TX_SIZE / cat->height;
		if (tex_y >= 0 && tex_y < TX_SIZE)
		{
			color = get_sprite_color(data, cat, tex_x, tex_y);
			if (color != 0x737373)
				my_mlx_pixel_put_2(data, st, y, color);
		}
		y++;
	}
}

int	get_sprite_color(t_data *data, t_sprite *cat, int tex_x, int tex_y)
{
	int	color;

	color = 0;
	if (cat->type == DEMO)
		color = data->demo_sprite[cat->frame][TX_SIZE * tex_y + tex_x];
	else if (cat->type == CAT)
		color = data->cat_sprite[cat->frame][TX_SIZE * tex_y + tex_x];
	return (color);
}

void	finish_game(t_data *data)
{
	t_coord	tex;
	int		color;
	t_coord	pos;
	int		st;
	int		y;

	pos.x = (IMAGE_WIDTH / 2) - (TX_SIZE / 2);
	pos.y = (IMAGE_HEIGHT / 2) - (TX_SIZE / 2);
	st = pos.x;
	while (st < pos.x + TX_SIZE)
	{
		tex.x = (st - pos.x) * TX_SIZE / TX_SIZE;
		y = pos.y;
		while (y < pos.y + TX_SIZE)
		{
			tex.y = (y - pos.y) * TX_SIZE / TX_SIZE;
			color = data->finish_texture[TX_SIZE * tex.y + tex.x];
			if (color != 0x737373)
				my_mlx_pixel_put_2(data, st, y, color);
			y++;
		}
		st++;
	}
}
