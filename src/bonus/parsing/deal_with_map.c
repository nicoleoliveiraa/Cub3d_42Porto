/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:12:16 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

char	*is_filled(t_data *data, char *id)
{
	if (!ft_strcmp(id, "NO"))
		return (data->t_north);
	else if (!ft_strcmp(id, "SO"))
		return (data->t_south);
	else if (!ft_strcmp(id, "WE"))
		return (data->t_west);
	else if (!ft_strcmp(id, "EA"))
		return (data->t_east);
	else if (!ft_strcmp(id, "F"))
		return (data->floor_color);
	else
		return (data->ceiling_color);
}

bool	have_more_line(char *map)
{
	int	i;

	i = -1;
	while (map[++i] && map[i] != '\n')
	{
		if (!is_space(map[i]))
			return (true);
	}
	return (false);
}

bool	have_more(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (!is_space(map[i]))
			return (true);
	}
	return (false);
}

bool	empty_lines_in_map(char	*map)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (map[i] && (is_space(map[i]) || map[i] == '\n'))
		i++;
	j = i;
	while (map[i++])
	{
		if (map[i] == '\n')
		{
			line = ft_substr(map, (unsigned int)(j), i - j + 1);
			if (ft_strcmp(line, "\n") == 0 && have_more(map + j))
			{
				if (line)
					free(line);
				return (true);
			}
			if (line)
				free(line);
			j = i + 1;
		}
	}
	return (false);
}

void	separate_map(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (data->data_file[++i])
	{
		if (data->data_file[i] == '\n' || data->data_file[i + 1] == '\0')
		{
			if (is_empty_line(data->data_file + j, i - j))
			{
				j = i + 1;
				continue ;
			}
			if (fill_data(data, j, i))
				break ;
			j = i + 1;
		}
	}
}
