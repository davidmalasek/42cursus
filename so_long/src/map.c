/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:08:49 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/18 18:40:38 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Width of a map
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

// Height of a map
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

t_coordinates	find_start_pos(char **array, int size_x, int size_y)
{
	int	y;
	int	x;

	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			if (array[y][x] == 'P')
				return ((t_coordinates){y, x});
			x++;
		}
		y++;
	}
	return ((t_coordinates){-1, -1});
}

int	count_coll(char **array, int size_x, int size_y)
{
	int	y;
	int	x;
	int	coll_count;

	y = 0;
	coll_count = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			if (array[y][x] == 'C')
				coll_count++;
			x++;
		}
		y++;
	}
	return (coll_count);
}

struct s_map	init_map(char *map)
{
	struct s_map	map_obj;

	map_obj.size_x = get_size_x(map);
	map_obj.size_y = get_size_y(map);
	map_obj.array = string_to_array(map);
	map_obj.player_pos = find_start_pos(map_obj.array, map_obj.size_x,
			map_obj.size_y);
	map_obj.total_coll = count_coll(map_obj.array, map_obj.size_x,
			map_obj.size_y);
	map_obj.coll_picked = 0;
	map_obj.number_of_movements = 0;
	return (map_obj);
}
