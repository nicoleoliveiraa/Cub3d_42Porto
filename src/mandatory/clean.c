/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:51:24 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/25 11:36:26 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(t_map *map_inf)
{
	free(map_inf->p_position);
	free(map_inf->m_position);
	if (map_inf->map_rect)
		ptr_free(map_inf->map_rect);
	free(map_inf);
}

void	free_game(t_data *data)
{
	if (data->game->image)
	{
		mlx_destroy_image(data->game->mlx, data->game->image->img);
		free(data->game->image);
	}
	if (data->game)
	{
		if (data->game->mlx_win)
			mlx_destroy_window(data->game->mlx, data->game->mlx_win);
		if (data->game->mlx)
		{
			if (data->game->mlx)
				mlx_destroy_display(data->game->mlx);
			free(data->game->mlx);
		}
		free(data->game);
	}
}

void	free_data(t_data *data)
{
	int	i;

	i = -1;
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
	while (++i < 4)
		if (data->texture_buffer[i])
			free(data->texture_buffer[i]);
	free_game(data);
	free_map(data->map_inf);
}

void	deal_with_error(t_data *data, char *message)
{
	free_data(data);
	printf("Error\n");
	printf("%s\n", message);
	exit(1);
}

void	*ptr_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}
