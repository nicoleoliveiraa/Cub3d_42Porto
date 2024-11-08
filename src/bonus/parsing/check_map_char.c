/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:56:28 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/23 17:09:33 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

//  ==============================================================
//  						MANDATORY PART
//  ==============================================================

/* bool	is_valid_character(int c)
{
	if (is_space(c) || is_player(c) || c == '0' || c == '1')
		return (true);
	return (false);
} */

//  ==============================================================
//  						BONUS PART
//  ==============================================================
bool	is_valid_character(int c)
{
	if (is_space(c) || is_player(c) || c == '0' || c == '1' || c == 'C' \
		|| c == 'F' || c == 'D')
	{
		if (c == 'D')
			get_data()->game->demo_cats++;
		if (c == 'F')
			get_data()->game->good_cats++;
		return (true);
	}
	return (false);
}

bool	valid_player(t_data *data, char c, int i, int j)
{
	if (is_player(c))
	{
		if (!data->map_inf->p_orientation)
		{
			data->map_inf->p_position->x = (float)j + 0.5;
			data->map_inf->p_position->y = (float)i + 0.5;
			data->map_inf->p_orientation = c;
		}
		else
			return (false);
	}
	return (true);
}

void	largest_line(t_data *data, int size)
{
	if (data->map_inf->width < size)
		data->map_inf->width = size;
}

void	validate_map_characters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!is_valid_character(data->map[i][j]))
				deal_with_error(data, ER_INV_CHAR);
			if (!valid_player(data, data->map[i][j], i, j))
				deal_with_error(data, ER_ONE_PLAYER);
			if (data->map[i][j] == 'F' || data->map[i][j] == 'D')
				data->game->nbr_cats++;
			j++;
		}
		largest_line(data, j);
		i++;
	}
	data->map_inf->height = i;
	if (data->map_inf->height < 3 || data->map_inf->width < 3)
		deal_with_error(data, "Too small of a map!");
	if (!data->map_inf->p_orientation)
		deal_with_error(data, ER_NOT_PLAYER);
}
