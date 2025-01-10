/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:14:26 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/10 17:29:50 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <fcntl.h>  // For open()
# include <stddef.h> // For size_t
# include <stdio.h>  // For perror()
# include <stdlib.h> // For NULL, malloc()
# include <unistd.h> // For read(), close()

// minilibx-linux
# include "../minilibx-linux/mlx.h"

// X11 events
# include <X11/X.h>
# include <X11/keysym.h>

// Sprites
# define SPRITE_SIZE 32

# define SPRITE_DIR "sprites/"

# define WALL SPRITE_DIR "wall.xpm"
# define PLAYER SPRITE_DIR "player.xpm"
# define COLL SPRITE_DIR "coll.xpm"
# define EXIT SPRITE_DIR "exit.xpm"
# define GROUND SPRITE_DIR "ground.xpm"

typedef struct
{
	int			x;
	int			y;
}				coordinates;

struct			map
{
	int			size_x;
	int			size_y;
	coordinates	player_pos;
	char		player_on;
	int			total_coll;
	int			coll_picked;
	int			steps;
	char		**array;
	int			number_of_movements;
};

struct			game
{
	struct map	map;
	void		*mlx;
	void		*mlx_win;
};

// Utils
void			*ft_calloc(size_t count, size_t size);
char			**allocate_matrix(int size_x, int size_y);
void			fill_matrix(char **matrix, char *map, int size_x, int size_y);
size_t			ft_strlen(const char *str);
int				ft_strcmp(char *s1, char *s2);

// Map
int				get_size_x(char *map);
int				get_size_y(char *map);
char			**string_to_array(char *map);
struct map		init_map(char *map);

// Map validation
int				is_map_regular(char *map);
int				is_map_rectangular(char *map);
int				is_map_valid(char *map);
int				is_map_surrounded_by_walls(char *map);
int				validate_char(char c, int *start, int *exit, int *collectibles);
int				check_map_items(struct map map);

// File
char			*read_from_file(char *filename);

// Logic
int				handle_keypress(int keycode, void *param);
int				handle_close(void);
void			handle_movement(int keycode, struct game *game);
void			move_player(struct game *game, int new_x, int new_y);

// Render
int				render_map(void *mlx, void *mlx_win, struct map map);

// Deinit
void			free_map(struct map *map);

#endif