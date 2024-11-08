/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene_description.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:18:08 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

static void	read_all_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	have_tabs(char *line)
{
	int	i;
	int	tabs;

	tabs = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '	')
			tabs++;
		i++;
	}
	return (tabs);
}

void	change_tabs(const char *line, char *new_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '	')
		{
			new_line[j++] = ' ';
			new_line[j++] = ' ';
			new_line[j++] = ' ';
			new_line[j++] = ' ';
		}
		else
			new_line[j++] = line[i];
		i++;
	}
	new_line[j] = '\0';
}

char	*replace_tabs(char *line)
{
	int		tabs;
	int		size;
	char	*new_line;

	tabs = have_tabs(line);
	if (tabs == 0)
		return (line);
	size = ft_strlen(line);
	new_line = ft_calloc(((size - tabs) + (tabs * 4) + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	change_tabs(line, new_line);
	free(line);
	return (new_line);
}

void	read_scene_description(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	char	*aux;
	char	*aux_map;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		deal_with_error(data, ER_OPEN_FAILED);
	aux_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = replace_tabs(line);
		aux = aux_map;
		aux_map = ft_strjoin(aux, line);
		free(line);
		free(aux);
	}
	read_all_file(fd);
	data->data_file = ft_strdup(aux_map);
	free(aux_map);
}
