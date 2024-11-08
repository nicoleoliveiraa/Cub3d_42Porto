/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:34:12 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

bool	is_all_num(char *c_nbrs)
{
	int	i;

	i = -1;
	while (c_nbrs[++i])
	{
		if (!ft_isdigit(c_nbrs[i]))
			return (false);
	}
	return (true);
}

void	validate_elements(t_data *data)
{
	textures_check(data, data->t_east);
	textures_check(data, data->t_west);
	textures_check(data, data->t_north);
	textures_check(data, data->t_south);
	color_check(data, data->ceiling_color);
	color_check(data, data->floor_color);
}

void	check_scene_description(int argc, char **argv, t_data *data)
{
	check_argc(argc, data);
	check_file_name(argv[1], data);
	read_scene_description(argv[1], data);
	check_empty_file(data);
	separate_map(data);
	validate_elements(data);
	validate_map_characters(data);
	validate_map(data);
	check_path(get_data());
}
