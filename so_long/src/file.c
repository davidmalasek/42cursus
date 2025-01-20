/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:06:19 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/20 13:30:42 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_file_extension(char *filename)
{
	int	len;

	if (!filename || !*filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strcmp(&filename[len - 4], ".ber") == 0);
}

char	*read_from_file(char *filename)
{
	char	*map;
	int		fd;
	char	buffer;
	int		char_count;

	char_count = 0;
	fd = open(filename, O_RDONLY);
	if (!is_valid_file_extension(filename))
		return (ft_printf("Error\n- invalid file\n"), exit(0), "");
	if (fd < 0)
		return (ft_printf("Error\n- cannot open provided file\n"), exit(0), "");
	while (read(fd, &buffer, 1) == 1)
		char_count++;
	if (char_count == 0)
		return (ft_printf("Error\n- provided file is empty.\n"), exit(0), "");
	map = (char *)malloc(sizeof(char) * (char_count + 1));
	if (!map)
		return (ft_printf("Error\n- failed to allocate memory for the map\n"),
			exit(0), "");
	close(fd);
	fd = open(filename, O_RDONLY);
	read(fd, map, char_count);
	map[char_count] = '\0';
	return (map);
}
