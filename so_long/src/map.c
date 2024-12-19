/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:08:49 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/19 12:40:33 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_size_x(char *map)
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

int	get_size_y(char *map)
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

void	free_matrix(char **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**allocate_matrix(int size_x, int size_y)
{
	char	**matrix;
	int		i;

	matrix = (char **)calloc(size_y, sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < size_y)
	{
		matrix[i] = (char *)calloc(size_x + 1, sizeof(char));
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

void	fill_matrix(char **matrix, char *map, int size_x, int size_y)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (*map)
	{
		if (*map == '\n')
		{
			matrix[row][col] = '\0';
			row++;
			col = 0;
		}
		else if (row < size_y && col < size_x)
		{
			matrix[row][col] = *map;
			col++;
		}
		map++;
	}
}

char	**string_to_array(char *map)
{
	int		size_x;
	int		size_y;
	char	**matrix;

	size_x = get_size_x(map);
	size_y = get_size_y(map);
	matrix = allocate_matrix(size_x, size_y);
	if (!matrix)
		return (NULL);
	fill_matrix(matrix, map, size_x, size_y);
	return (matrix);
}

int	find_start_pos(struct map *map_obj)
{
	int	x;
	int	y;

	if (!map_obj || !map_obj->array)
		return (-1);
	x = 0;
	while (x < map_obj->size_x)
	{
		y = 0;
		while (y < map_obj->size_y)
		{
			if (map_obj->array[x][y] == 'P')
			{
				map_obj->start_x = x;
				map_obj->start_y = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (-1);
}

struct map	init_map(char *map)
{
	struct map	map_obj;

	map_obj.size_x = get_size_y(map);
	map_obj.size_y = get_size_x(map);
	map_obj.array = string_to_array(map);
	find_start_pos(&map_obj);
	return (map_obj);
}
