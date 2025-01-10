/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:49:21 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/10 17:16:29 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
	char		*file_content;
	struct map	map_obj;
	struct game	game;
	void		*mlx;
	void		*mlx_win;

	file_content = read_from_file("./maps/map1.ber");
	if (is_map_valid(file_content))
		map_obj = init_map(file_content);
	else
		return (printf("Error\n- provided map is not valid\n"), exit(0), 0);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map_obj.size_x * SPRITE_SIZE, map_obj.size_y
			* SPRITE_SIZE, "so_long");
	game.mlx = mlx;
	game.mlx_win = mlx_win;
	game.map = map_obj;
	mlx_key_hook(mlx_win, handle_keypress, (void *)&game);
	mlx_hook(game.mlx_win, 17, 0, handle_close, NULL);
	mlx_loop(mlx);
	return (0);
}

/*
TODO
- replace printf with ft_printf
- proper errors everywhere
- valgrind finds a lot of leaks, so deinit?
*/