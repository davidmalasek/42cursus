/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:08:49 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/12 22:35:06 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_x(char *map)
{
	int	x;

	x = 0;
	while (*map)
	{
		if (*map == '\n')
			return (x);
		else
			x++;
		map++;
	}
	return (-1);
}

int	get_y(char *map)
{
	int	y;

	if (!map || *map == '\0')
		return (-1);
	y = 0;
	while (*map)
	{
		if (*map == '\n')
		{
			y++;
		}
		map++;
	}
	if (*(map - 1) != '\n')
		y++;
	return (y);
}

char	**string_to_array(char *map)
{
	char	**matrix;
	int		row;
	int		col;
	int		i;

	row = 0;
	col = 0;
	matrix = (char **)ft_calloc(get_y(map), sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < get_y(map))
	{
		matrix[i] = (char *)ft_calloc(get_x(map) + 1, sizeof(char));
		if (!matrix[i])
			return (NULL);
	}
	while (*map)
	{
		if (*map == '\n')
		{
			matrix[row][col] = '\0';
			row++;
			col = 0;
		}
		else
			matrix[row][col++] = *map;
		map++;
	}
	if (col > 0)
		matrix[row][col] = '\0';
	return (matrix);
}

struct map	init_map(char *map)
{
	struct map	map_obj;

	map_obj.x = get_x(map);
	map_obj.y = get_y(map);
	map_obj.array = string_to_array(map);
	return (map_obj);
}
