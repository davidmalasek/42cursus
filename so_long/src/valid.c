/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:08:12 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/13 14:10:29 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
MAP:

0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.

Valid map checklist:
- map must contain 1 exit, at least 1 collectible,
	and 1 starting position to be valid
- map must be rectangular
- map must be closed/surrounded by walls, if it’s not,
	the program must return an error
- map must have a valid path

If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way,
	and return "Error\n" followed by an explicit error message of
your choice.

Valid map:

1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
*/

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
int	is_map_valid(char *map)
{
	printf("Map is regular: %d\n", is_map_regular(map));
	printf("Map is rectangular: %d\n", is_map_rectangular(map));
	printf("Map X: %d\n", get_size_x(map));
	printf("Map Y: %d\n", get_size_y(map));
	printf("Map is surrounded by walls: %d\n", is_map_surrounded_by_walls(map));
	return (is_map_regular(map), is_map_rectangular(map),
		is_map_surrounded_by_walls(map));
}
