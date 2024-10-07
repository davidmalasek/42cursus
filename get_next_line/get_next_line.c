/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:11 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/07 20:29:32 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *buffer, int end)
{
	char	*line;
	int		i;

	line = malloc(end + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (i <= end)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*buffer[BUFFER_SIZE];
	int			i;

	i = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	buffer[bytes_read] = '\0';
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (extract_line(buffer, i));
		i++;
	}
	return (NULL);
}

int	main(void)
{
	get_next_line(0);
}