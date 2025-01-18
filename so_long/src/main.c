/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:49:21 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/18 19:01:28 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
	char			*file_content;
	struct s_map	map_obj;
	struct s_game	game;
	void			*mlx;
	void			*mlx_win;

	file_content = read_from_file("./maps/map2.ber");
	if (is_map_valid(file_content))
		map_obj = init_map(file_content);
	else
		return (ft_printf("Error\n- provided map is not valid\n"),
			free(file_content), exit(0), 0);
	free(file_content);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map_obj.size_x * SPRITE_SIZE, map_obj.size_y
			* SPRITE_SIZE, "so_long");
	game.mlx = mlx;
	game.mlx_win = mlx_win;
	game.map = map_obj;
	mlx_key_hook(mlx_win, handle_keypress, (void *)&game);
	mlx_hook(mlx_win, 17, 0, handle_close, &game);
	mlx_loop(mlx);
	return (0);
}
