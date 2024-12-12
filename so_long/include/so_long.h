/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:14:26 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/12 22:39:02 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <fcntl.h>  // For open()
# include <stddef.h> // For size_t
# include <stdio.h>  // For perror()
# include <stdlib.h> // For NULL, malloc()
# include <unistd.h> // For read(), close()

struct		map
{
	int		x;
	int		y;
	char	**array;
};

int			get_x(char *map);
int			get_y(char *map);
char		**string_to_array(char *map);
struct map	init_map(char *map);
void		*ft_calloc(size_t count, size_t size);
int			is_map_regular(char *map);
int			is_map_rectangular(char *map);
int			is_map_valid(char *map);
char		*read_from_file(char *filename);
int			is_map_surrounded_by_walls(char *map);

#endif