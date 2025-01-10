/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:15:44 by dmalasek          #+#    #+#             */
/*   Updated: 2025/01/10 16:15:14 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*get_sprite(char c)
{
	if (c == '1')
		return (WALL);
	if (c == '0')
		return (GROUND);
	if (c == 'P')
		return (PLAYER);
	if (c == 'C')
		return (COLL);
	if (c == 'E')
		return (EXIT);
	return (NULL);
}

int	render_map(void *mlx, void *win, struct map map)
{
	int		y;
	int		x;
	int		sprite_width;
	int		sprite_height;
	char	*s;

	y = 0;
	while (y < map.size_y)
	{
		x = 0;
		while (x < map.size_x)
		{
			s = get_sprite(map.array[y][x]);
			if (s)
				mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx, s,
						&sprite_width, &sprite_height), x * SPRITE_SIZE, y
					* SPRITE_SIZE);
			x++;
		}
		y++;
	}
	return (1);
}
