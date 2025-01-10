/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:08:12 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/10 17:06:01 by dmalasek         ###   ########.fr       */
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
			if (!first_row_length)
				first_row_length = x_count;
			else if (x_count != first_row_length)
				return (0);
			y_count++;
			x_count = 0;
		}
		else
			x_count++;
		map++;
	}
	if (x_count && (x_count != first_row_length))
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

int	has_map_valid_path(struct map map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map.size_y || y >= map.size_x)
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

// FOR EVALUATION, UNCOMMENT THIS

int	is_map_valid(char *map)
{
	struct map	map_matrix;

	map_matrix = init_map(map);
	return (is_map_regular(map) && is_map_rectangular(map)
		&& is_map_surrounded_by_walls(map) && check_map_items(map_matrix)
		&& has_map_valid_path(map_matrix, map_matrix.player_pos.x,
			map_matrix.player_pos.y));
}

// FOR DEBUGGING, UNCOMMENT THIS

// int	is_map_valid(char *map)
// {
// 	struct map	map_matrix;

// 	printf("\nMap loaded from file:\n\n");
// 	printf("%s", map);
// 	printf("\n\n---\n\n");
// 	printf("Regular: %s\n", is_map_regular(map) ? "✅" : "❌");
// 	printf("Rectangular: %s\n", is_map_rectangular(map) ? "✅" : "❌");
// 	printf("Surrounded by walls: %s\n",
// 		is_map_surrounded_by_walls(map) ? "✅" : "❌");
// 	map_matrix = init_map(map);
// 	printf("Valid items: %s\n", check_map_items(map_matrix) ? "✅" : "❌");
// 	printf("Valid path: %s\n", has_map_valid_path(map_matrix,
// 			map_matrix.player_pos.x, map_matrix.player_pos.y) ? "✅" : "❌");
// 	printf("\n");
// 	printf("Width: %d\n", get_size_x(map));
// 	printf("Height: %d\n", get_size_y(map));
// 	printf("Player starts at row %d, column %d\n\n", map_matrix.player_pos.x,
// 		map_matrix.player_pos.y);
// 	return (is_map_regular(map) && is_map_rectangular(map)
// 		&& is_map_surrounded_by_walls(map) && check_map_items(map_matrix)
// 		&& has_map_valid_path(map_matrix, map_matrix.player_pos.x,
// 			map_matrix.player_pos.y));
// }
