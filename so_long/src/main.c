/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:49:21 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/09 16:58:05 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int main (void) {
// 	char	*file_content;

// 	// TODO: Prevent map from loading when the file doesn't exist
// 	// TODO: Prevent map from loading when the file doesn't have .ber suffix
// 	file_content = read_from_file("./maps/map1.ber");
// 	printf("\nMap loaded from file:\n\n");
// 	printf("%s", file_content);
// 	printf("\n\n---\n\n");
// 	is_map_valid(file_content);
// 	printf("\n");
// 	init_map(file_content);
// }

int	main(void)
{
	char		*file_content;
	struct map	map_obj;
	void		*mlx;
	void		*mlx_win;
	void		*wall;
	void		*player;
	void		*collectible;
	void		*ground;
	void		*exit;
	int			x;
	int			y;
	int			sprite_width;
	int			sprite_height;

	file_content = read_from_file("./maps/map1.ber");
	if (is_map_valid(file_content))
	{
		map_obj = init_map(file_content);
	}
	mlx = mlx_init();
	// The multiplication is based on size of the sprite used.
	mlx_win = mlx_new_window(mlx, map_obj.size_x * SPRITE_SIZE, map_obj.size_y
			* SPRITE_SIZE, "so_long");
	wall = mlx_xpm_file_to_image(mlx, "sprites/wall.xpm", &sprite_width,
			&sprite_height);
	player = mlx_xpm_file_to_image(mlx, "sprites/player.xpm", &sprite_width,
			&sprite_height);
	collectible = mlx_xpm_file_to_image(mlx, "sprites/coll.xpm", &sprite_width,
			&sprite_height);
	exit = mlx_xpm_file_to_image(mlx, "sprites/exit.xpm", &sprite_width,
			&sprite_height);
	ground = mlx_xpm_file_to_image(mlx, "sprites/ground.xpm", &sprite_width,
			&sprite_height);
	y = 0;
	while (y < map_obj.size_y)
	{
		x = 0;
		while (x < map_obj.size_x)
		{
			if (map_obj.array[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, wall, x * SPRITE_SIZE, y
					* SPRITE_SIZE);
			else if (map_obj.array[y][x] == '0')
				mlx_put_image_to_window(mlx, mlx_win, ground, x * SPRITE_SIZE, y
					* SPRITE_SIZE);
			else if (map_obj.array[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, player, x * SPRITE_SIZE, y
					* SPRITE_SIZE);
			else if (map_obj.array[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, collectible, x
					* SPRITE_SIZE, y * SPRITE_SIZE);
			else if (map_obj.array[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, exit, x * SPRITE_SIZE, y
					* SPRITE_SIZE);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
	return (0);
}

/*
TODO: replace printf with ft_printf

*/