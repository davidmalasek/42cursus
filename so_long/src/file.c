/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:06:19 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/12 18:11:29 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// TODO: proper error printing
char	*read_from_file(char *filename)
{
	char	*map;
	int		fd;
	char	buffer;
	int		char_count;

	char_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("Error \n");
	while (read(fd, &buffer, 1) == 1)
		char_count++;
	if (char_count == 0)
		perror("Error \n");
	map = (char *)malloc(sizeof(char) * (char_count + 1));
	if (!map)
		perror("Error \n");
	close(fd);
	fd = open(filename, O_RDONLY);
	read(fd, map, char_count);
	map[char_count] = '\0';
	return (map);
}
