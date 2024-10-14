/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:11 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/14 18:05:59 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*append_to_stash(char *stash, char *buffer)
{
	char	*new_stash;

	new_stash = (char *)malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	ft_strlcat(new_stash, stash, ft_strlen(stash) + 1);
	ft_strlcat(new_stash, buffer, ft_strlen(buffer) + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*stash;
	int			bytes_read;

	// char		*line;
	bytes_read = 0;
	stash = NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytes_read != -1)
		{
			stash = append_to_stash(stash, buffer);
			if (get_newline(stash) != -1)
			{
				return (ft_substr(stash, 0, get_newline(stash)));
			}
		}
	}
	return (NULL);
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	if (close(fd) == -1)
	{
		perror("Error closing file");
		return (1);
	}

	return (0);
}