/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:06:06 by dmalasek          #+#    #+#             */
/*   Updated: 2025/01/18 18:38:56 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Checks if map has 1 starting point, 1 exit and at least 1 collectible.
int	validate_char(char c, int *start, int *exit, int *collectibles)
{
	if (c == 'P')
		(*start)++;
	else if (c == 'E')
		(*exit)++;
	else if (c == 'C')
		(*collectibles)++;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

int	check_map_items(struct s_map map)
{
	int	i;
	int	e;
	int	s_count;
	int	e_count;
	int	c_count;

	s_count = 0;
	e_count = 0;
	c_count = 0;
	i = 0;
	while (i < map.size_y)
	{
		e = 0;
		while (e < map.size_x)
		{
			if (!validate_char(map.array[i][e], &s_count, &e_count, &c_count))
				return (0);
			e++;
		}
		i++;
	}
	return (s_count == 1 && e_count == 1 && c_count >= 1);
}
