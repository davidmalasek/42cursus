/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:11 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/10 17:56:54 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Scans the input until it reaches \n or EOF

static int	scan(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*leftover;
	char		*line;
	int			bytes_read;
	int			delimiter;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (leftover)
	{
		buffer = ft_strdup(leftover);
		free(leftover);
		leftover = NULL;
	}
	else
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
	}
	delimiter = scan(buffer);
	if (delimiter != -1)
	{
		line = ft_substr(buffer, 0, delimiter + 1);
		if (buffer[delimiter + 1] != '\0')
			leftover = ft_substr(buffer, delimiter + 1, BUFFER_SIZE - delimiter
					+ 1);
		free(buffer);
		return (line);
	}
	free(buffer);
	return (NULL);
}
