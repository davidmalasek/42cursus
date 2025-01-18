/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:14:26 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/18 18:46:23 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>  // For open()
# include <stddef.h> // For size_t
# include <stdio.h>  // For perror()
# include <stdlib.h> // For NULL, malloc()
# include <unistd.h> // For read(), close()

// minilibx
# include "../minilibx_linux/mlx.h"
# include "../minilibx_macos/mlx.h"

// ft_printf
# include "../ft_printf/ft_printf.h"

// X11 events (only for Linux)
# ifdef __linux__
#  include <X11/X.h>
#  include <X11/keysym.h>
# endif

// Different key code definitions for both systems
# ifdef __APPLE__ // macOS
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
# elif __linux__ // Linux
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
# endif

// Sprites
# define SPRITE_SIZE 50

# define WALL "sprites/wall.xpm"
# define PLAYER "sprites/player.xpm"
# define COLL "sprites/coll.xpm"
# define EXIT "sprites/exit.xpm"
# define GROUND "sprites/ground.xpm"

typedef struct s_coordinates
{
	int				x;
	int				y;
}					t_coordinates;

struct				s_map
{
	int				size_x;
	int				size_y;
	t_coordinates	player_pos;
	char			player_on;
	int				total_coll;
	int				coll_picked;
	int				steps;
	char			**array;
	int				number_of_movements;
};

struct				s_game
{
	struct s_map	map;
	void			*mlx;
	void			*mlx_win;
};

// Utils
void				*ft_calloc(size_t count, size_t size);
char				**allocate_matrix(int size_x, int size_y);
void				fill_matrix(char **matrix, char *map, int size_x,
						int size_y);
void				free_matrix(char **matrix, int rows);
void				free_mlx(struct s_game *game);
size_t				ft_strlen(const char *str);
int					ft_strcmp(char *s1, char *s2);

// Map
int					get_size_x(char *map);
int					get_size_y(char *map);
char				**string_to_array(char *map);
struct s_map		init_map(char *map);

// Map validation
int					is_map_regular(char *map);
int					is_map_rectangular(char *map);
int					is_map_valid(char *map);
int					is_map_surrounded_by_walls(char *map);
int					validate_char(char c, int *start, int *exit,
						int *collectibles);
int					check_map_items(struct s_map map);

// File
char				*read_from_file(char *filename);

// Logic
int					handle_keypress(int keycode, void *param);
int					handle_close(struct s_game *game);
void				handle_movement(int keycode, struct s_game *game);
void				move_player(struct s_game *game, int new_x, int new_y);

// Render
int					render_map(void *mlx, void *mlx_win, struct s_map map);

// Deinit
void				free_map(char **map);

#endif