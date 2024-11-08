/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:20:39 by lebarbos          #+#    #+#             */
/*   Updated: 2024/09/25 16:07:58 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	update_shrimp(t_game *game)
{
	if (!game->shrimp.visible)
		return ;
	game->shrimp.current_time += 0.02f;
	if (game->shrimp.current_time >= game->shrimp.frame_time)
	{
		game->shrimp.current_frame++;
		if (game->shrimp.current_frame >= SHRIMP_FRAMES)
		{
			game->shrimp.visible = false;
			game->shrimp.current_frame = 0;
			if (game->exorcise_cat_index >= 0)
			{
				game->cats[game->exorcise_cat_index].type = CAT;
				game->good_cats++;
				if (game->good_cats == game->nbr_cats)
				{
					get_data()->game_over = true;
					finish_game(get_data());
				}
			}
		}
		game->shrimp.current_time = 0;
	}
}

void	update_cats(t_sprite *sprites, int num_sprites )
{
	int	num_frames;
	int	i;

	i = -1;
	while (++i < num_sprites)
	{
		if (sprites[i].type == DEMO)
			num_frames = 13;
		else
			num_frames = 8;
		sprites[i].current_time += 0.02f;
		if (sprites[i].current_time >= sprites[i].frame_time)
		{
			sprites[i].frame = (sprites[i].frame + 1) % num_frames;
			sprites[i].current_time = 0;
		}
	}
}
