/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:15:44 by dmalasek          #+#    #+#             */
/*   Updated: 2025/01/18 18:38:56 by dmalasek         ###   ########.fr       */
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

void	render_tile(void *mlx, void *win, char *sprite_path, int coords[2])
{
	void	*img;
	int		size[2];

	img = mlx_xpm_file_to_image(mlx, sprite_path, &size[0], &size[1]);
	if (img)
	{
		mlx_put_image_to_window(mlx, win, img, coords[0] * SPRITE_SIZE,
			coords[1] * SPRITE_SIZE);
		mlx_destroy_image(mlx, img);
	}
}

void	render_row(void *mlx, void *win, struct s_map map, int row)
{
	int		col;
	int		coords[2];
	char	*sprite;

	coords[1] = row;
	col = 0;
	while (col < map.size_x)
	{
		sprite = get_sprite(map.array[row][col]);
		if (sprite)
		{
			coords[0] = col;
			render_tile(mlx, win, sprite, coords);
		}
		col++;
	}
}

int	render_map(void *mlx, void *win, struct s_map map)
{
	int	row;

	row = 0;
	while (row < map.size_y)
	{
		render_row(mlx, win, map, row);
		row++;
	}
	return (1);
}

// Function below works, it frees the sprites

// int	render_map(void *mlx, void *win, struct s_map map)
// {
// 	int		y;
// 	int		x;
// 	int		sprite_width;
// 	int		sprite_height;
// 	char	*s;

// 	y = 0;
// 	while (y < map.size_y)
// 	{
// 		x = 0;
// 		while (x < map.size_x)
// 		{
// 			s = get_sprite(map.array[y][x]);
// 			if (s)
// 			{
// 				if (mlx_xpm_file_to_image(mlx, s, &sprite_width,
// 						&sprite_height))
// 				{
// 					mlx_put_image_to_window(mlx, win, mlx_xpm_file_to_image(mlx,
// 							s, &sprite_width, &sprite_height), x * SPRITE_SIZE,
// 						y * SPRITE_SIZE);
// 					mlx_destroy_image(mlx, mlx_xpm_file_to_image(mlx, s,
// 							&sprite_width, &sprite_height));
// 				}
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (1);
// }
