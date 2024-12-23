/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:14:26 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/23 15:21:10 by dmalasek         ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

struct		map
{
	int		size_x;
	int		size_y;
	char	**array;
	int		start_x;
	int		start_y;
};

// Utils
void		*ft_calloc(size_t count, size_t size);

// Map
int			get_size_x(char *map);
int			get_size_y(char *map);
char		**string_to_array(char *map);
struct map	init_map(char *map);

// Map validation
int			is_map_regular(char *map);
int			is_map_rectangular(char *map);
int			is_map_valid(char *map);
int			is_map_surrounded_by_walls(char *map);

// File
char		*read_from_file(char *filename);

#endif