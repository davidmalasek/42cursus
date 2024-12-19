/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:08:12 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/19 12:50:32 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_map_regular(char *map)
{
	int	first_row_length;
	int	row_items_count;

	first_row_length = 0;
	row_items_count = 0;
	while (*map)
	{
		if (*map == '\n')
		{
			if (first_row_length == 0)
				first_row_length = row_items_count;
			else
			{
				if (row_items_count != first_row_length)
					return (0);
			}
			row_items_count = 0;
		}
		else
			row_items_count++;
		map++;
	}
	if (row_items_count != 0 && row_items_count != first_row_length)
		return (0);
	return (1);
}
// This function assumes that map is regular thanks to the order of the check functions.
int	is_map_rectangular(char *map)
{
	int	x_count;
	int	y_count;
	int	first_row_length;

	x_count = 0;
	y_count = 0;
	first_row_length = 0;
	while (*map)
	{
		if (*map == '\n')
		{
			y_count++;
			if (first_row_length == 0)
				first_row_length = x_count;
			x_count = 0;
		}
		else
			x_count++;
		map++;
	}
	if (x_count > 0)
	{
		y_count++;
		if (first_row_length == 0)
			first_row_length = x_count;
	}
	if (y_count == first_row_length)
		return (0);
	return (1);
}

int	is_map_surrounded_by_walls(char *map)
{
	int		i;
	char	**array;

	array = string_to_array(map);
	i = 0;
	while (i < get_size_x(map))
	{
		if (array[0][i] == '0' || array[get_size_y(map) - 1][i] == '0')
			return (0);
		i++;
	}
	i = 0;
	while (i < get_size_y(map))
	{
		if (array[i][0] == '0' || array[i][get_size_x(map) - 1] == '0')
			return (0);
		i++;
	}
	return (1);
}
// Checks if map has 1 starting point, 1 exit and at least 1 collectible.
int	check_map_items(char *map)
{
	int		i;
	int		e;
	char	**array;
	int		start_count;
	int		exit_count;
	int		collectible_count;

	start_count = 0;
	exit_count = 0;
	collectible_count = 0;
	array = string_to_array(map);
	i = 0;
	while (i < get_size_y(map))
	{
		e = 0;
		while (e < get_size_x(map))
		{
			if (array[i][e] == 'P')
				start_count++;
			else if (array[i][e] == 'E')
				exit_count++;
			else if (array[i][e] == 'C')
				collectible_count++;
			e++;
		}
		i++;
	}
	return (start_count == 1 && exit_count == 1 && collectible_count >= 1);
}

int	has_map_valid_path(struct map map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map.size_x || y >= map.size_y)
		return (0);
	if (map.array[x][y] == '1' || map.array[x][y] == 'V')
		return (0);
	if (map.array[x][y] == 'E')
		return (1);
	map.array[x][y] = 'V';
	if (has_map_valid_path(map, x + 1, y) || has_map_valid_path(map, x - 1, y)
		|| has_map_valid_path(map, x, y + 1) || has_map_valid_path(map, x, y
			- 1))
		return (1);
	return (0);
}

int	is_map_valid(char *map)
{
	struct map	map_matrix;

	// TODO: Maybe at some point work with matrix instead of string
	printf("Regular: %s\n", is_map_regular(map) ? "✅" : "❌");
	printf("Rectangular: %s\n", is_map_rectangular(map) ? "✅" : "❌");
	printf("Surrounded by walls: %s\n",
		is_map_surrounded_by_walls(map) ? "✅" : "❌");
	printf("Valid items: %s\n", check_map_items(map) ? "✅" : "❌");
	map_matrix = init_map(map);
	printf("Valid path: %s\n", has_map_valid_path(map_matrix,
			map_matrix.start_x, map_matrix.start_y) ? "✅" : "❌");
	printf("\n");
	printf("Width: %d\n", get_size_x(map));
	printf("Height: %d\n", get_size_y(map));
	printf("Player starts at row %d, column %d\n", map_matrix.start_x,
		map_matrix.start_y);
	return (is_map_regular(map), is_map_rectangular(map),
		is_map_surrounded_by_walls(map));
}
