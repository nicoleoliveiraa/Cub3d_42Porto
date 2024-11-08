/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:51:24 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	free_data(t_data *data)
{
	free_paths(data);
	free_textures(data);
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
			mlx_destroy_display(data->game->mlx);
			free(data->game->mlx);
		}
		free(data->game);
	}
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

int	close_window(void)
{
	free_data(get_data());
	exit (0);
	return (0);
}
