/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:37:49 by dmalasek          #+#    #+#             */
/*   Updated: 2025/01/18 18:40:38 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(struct s_game *game, int new_x, int new_y)
{
	char	next_tile;

	next_tile = game->map.array[new_x][new_y];
	if (next_tile == '0' || next_tile == 'C' || next_tile == 'E')
	{
		if (next_tile == 'C')
			game->map.coll_picked++;
		else if (next_tile == 'E')
		{
			if (game->map.coll_picked != game->map.total_coll)
				return ;
			else
			{
				ft_printf("You won!\n");
				handle_close(game);
			}
		}
		game->map.array[game->map.player_pos.x][game->map.player_pos.y] = '0';
		game->map.array[new_x][new_y] = 'P';
		game->map.player_pos = (t_coordinates){new_x, new_y};
		game->map.number_of_movements++;
		ft_printf("%d\n", game->map.number_of_movements);
	}
}

void	handle_movement(int keycode, struct s_game *game)
{
	int	x;
	int	y;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	if (keycode == KEY_W)
		move_player(game, x - 1, y);
	else if (keycode == KEY_A)
		move_player(game, x, y - 1);
	else if (keycode == KEY_S)
		move_player(game, x + 1, y);
	else if (keycode == KEY_D)
		move_player(game, x, y + 1);
}

int	handle_keypress(int keycode, void *param)
{
	struct s_game	*game;

	game = (struct s_game *)param;
	if (keycode == 65307)
		handle_close(game);
	handle_movement(keycode, game);
	render_map(game->mlx, game->mlx_win, game->map);
	return (1);
}

int	handle_close(struct s_game *game)
{
	free_map(game->map.array);
	free_mlx(game);
	exit(0);
}
