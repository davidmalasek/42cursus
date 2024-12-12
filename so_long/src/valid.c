/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:08:12 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/12 22:40:44 by davidmalase      ###   ########.fr       */
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

// TODO: finish this function
int	is_map_surrounded_by_walls(char *map)
{
	struct map	map_obj;

	map_obj.array = string_to_array(map);
}
int	is_map_valid(char *map)
{
	printf("Map is regular: %d\n", is_map_regular(map));
	printf("Map is rectangular: %d\n", is_map_rectangular(map));
	printf("Map X: %d\n", get_x(map));
	printf("Map Y: %d\n", get_y(map));
	return (is_map_regular(map), is_map_rectangular(map));
}
