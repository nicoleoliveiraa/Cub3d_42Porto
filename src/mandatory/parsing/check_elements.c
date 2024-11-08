/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:42:42 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/25 15:32:56 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	check_permission(t_data *data, char *element)
{
	int	fd;

	fd = open(element, F_OK);
	if (fd < 0)
	{
		close(fd);
		deal_with_error(data, "Texture path not found!");
	}
	fd = open(element, X_OK);
	if (fd < 0)
	{
		close(fd);
		deal_with_error(data, "No permission to access the texture path!");
	}
}

void	textures_check(t_data *data, char *element)
{
	int	i;

	i = -1;
	while (element[++i])
	{
		if (is_space(element[i]))
			deal_with_error(data, ER_TEXTURE);
	}
	check_permission(data, element);
}

bool	rgb_limits(char *c_nbrs)
{
	int	nbr;

	nbr = ft_atoi(c_nbrs);
	if (nbr < 0 || nbr > 255)
		return (false);
	return (true);
}

void	check_color_numbers(t_data *data, char **c_nbrs)
{
	int	i;

	i = -1;
	while (c_nbrs[++i])
	{
		if ((!is_all_num(c_nbrs[i]) || !rgb_limits(c_nbrs[i])) \
			&& !is_exception(c_nbrs[i]))
		{
			ptr_free(c_nbrs);
			deal_with_error(data, ER_RGB_NBR);
		}
	}
}

void	color_check(t_data *data, char *element)
{
	char	**split_el;

	if (!check_quotes(element))
		deal_with_error(data, ER_RGB_NBR);
	split_el = ft_split(element, ',');
	if (split_size(split_el) != 3)
	{
		ptr_free(split_el);
		deal_with_error(data, ER_RGB_NBR);
	}
	check_color_numbers(data, split_el);
	ptr_free(split_el);
}
