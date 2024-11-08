/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:00:20 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/25 15:08:03 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

char	*get_line(t_data *data, int j, int i)
{
	char	*line;
	int		k;

	k = 0;
	if (!have_more_line(data->data_file + j))
		return (NULL);
	while (is_space(data->data_file[j]))
		j++;
	line = malloc(sizeof(char) * (i - j + 1));
	while (data->data_file[j] && j < i)
	{
		if (is_space(data->data_file[j]) && \
			!have_more_line(data->data_file + j))
			break ;
		line[k++] = data->data_file[j++];
	}
	line[k] = '\0';
	return (line);
}

void	copy_line(t_data *data, int j, int i, char *id)
{
	char	*line;

	if (is_filled(data, id))
		deal_with_error(data, "Repeated scene element definitions!");
	line = get_line(data, j, i);
	if (!line)
		deal_with_error (data, ER_INCOMPLET);
	if (!ft_strcmp(id, "NO"))
		data->t_north = ft_strdup(line);
	else if (!ft_strcmp(id, "SO"))
		data->t_south = ft_strdup(line);
	else if (!ft_strcmp(id, "WE"))
		data->t_west = ft_strdup(line);
	else if (!ft_strcmp(id, "EA"))
		data->t_east = ft_strdup(line);
	else if (!ft_strcmp(id, "F"))
		data->floor_color = ft_strdup(line);
	else if (!ft_strcmp(id, "C"))
		data->ceiling_color = ft_strdup(line);
	free(line);
}

void	get_scene_elements(t_data *data, int j, int i)
{
	char	*aux;

	aux = data->data_file;
	if (aux[j] == 'N' && aux[j + 1] == 'O' && is_space(aux[j + 2]))
		copy_line(data, j + 2, i, "NO");
	else if (aux[j] == 'S' && aux[j + 1] == 'O' && is_space(aux[j + 2]))
		copy_line(data, j + 2, i, "SO");
	else if (aux[j] == 'W' && aux[j + 1] == 'E' && is_space(aux[j + 2]))
		copy_line(data, j + 2, i, "WE");
	else if (aux[j] == 'E' && aux[j + 1] == 'A' && is_space(aux[j + 2]))
		copy_line(data, j + 2, i, "EA");
	else if (aux[j] == 'F' && is_space(aux[j + 1]))
		copy_line(data, j + 1, i, "F");
	else if (aux[j] == 'C' && is_space(aux[j + 1]))
		copy_line(data, j + 1, i, "C");
	else
		deal_with_error(data, ER_SCENE_EL);
}

bool	is_element(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3) || \
		!ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3) || \
		!ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
		return (true);
	return (false);
}

bool	fill_data(t_data *data, int j, int i)
{
	char		*map;

	if (is_element(data->data_file + j))
	{
		get_scene_elements(data, j, i);
		if (!have_more(data->data_file + i))
			deal_with_error(data, ER_INCOMPLET);
		return (false);
	}
	is_map(data);
	map = ft_strdup(data->data_file + j);
	if (empty_lines_in_map(map))
	{
		free(map);
		deal_with_error(data, "Empty lines in the map!");
	}
	data->map = ft_split(map, '\n');
	free(map);
	return (true);
}
