/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:51:24 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	free_map(t_map *map_inf)
{
	free(map_inf->p_position);
	free(map_inf->m_position);
	if (map_inf->map_rect)
		ptr_free(map_inf->map_rect);
	free(map_inf);
}

void	free_texture_array(int **textures, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (textures[i])
			free(textures[i]);
		i++;
	}
}

void	free_textures(t_data *data)
{
	free_texture_array(data->texture_buffer, 6);
	free_texture_array(data->cat_sprite, 8);
	free_texture_array(data->demo_sprite, 13);
	free_texture_array(data->shrimp_sprite, 11);
	free_texture_array(data->start_texture, 4);
	if (data->finish_texture)
		free(data->finish_texture);
	if (data->game->cats)
		free(data->game->cats);
}

void	free_paths(t_data *data)
{
	if (data->ceiling_color)
		free(data->ceiling_color);
	if (data->floor_color)
		free(data->floor_color);
	if (data->data_file)
		free(data->data_file);
	if (data->t_east)
		free(data->t_east);
	if (data->t_north)
		free(data->t_north);
	if (data->t_south)
		free(data->t_south);
	if (data->t_west)
		free(data->t_west);
	if (data->map)
		ptr_free(data->map);
}
