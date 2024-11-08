/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:16:16 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/25 15:11:30 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

bool	is_exception(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' && c[i + 1] == '0' && c[i + 2] == '\0')
		return (true);
	return (false);
}

void	check_argc(int argc, t_data *data)
{
	if (argc != 2)
		deal_with_error(data, ER_ARGC);
}

void	check_file_name(char *file_name, t_data *data)
{
	if (!(ft_strnstr((file_name + (ft_strlen(file_name) - 4)), ".cub", 4)))
		deal_with_error(data, ER_EXTENSION_FILE);
	if (ft_strlen(file_name) <= 4)
		deal_with_error(data, ER_EXTENSION_FILE);
}

void	check_empty_file(t_data *data)
{
	int	i;

	i = -1;
	while (data->data_file[++i])
	{
		if (ft_isprint(data->data_file[i]))
			return ;
	}
	deal_with_error(data, ER_EMPTY_FILE);
}

void	is_map(t_data *data)
{
	if (!data->ceiling_color || !data->floor_color || !data->t_east \
	|| !data->t_north || !data->t_south || !data->t_west)
		deal_with_error(data, ER_SCENE_EL);
}
