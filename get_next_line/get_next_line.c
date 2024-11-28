/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:49:50 by dmalasek          #+#    #+#             */
/*   Updated: 2024/11/28 15:06:50 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	append_to_stash(char **stash, char *buffer)
{
	char	*new_stash;
	size_t	total_len;

	total_len = ft_strlen(buffer);
	if (*stash)
		total_len += ft_strlen(*stash);
	new_stash = (char *)malloc(total_len + 1);
	if (!new_stash)
		return (-1);
	new_stash[0] = '\0';
	if (*stash)
		ft_strlcpy(new_stash, *stash, ft_strlen(*stash) + 1);
	ft_strlcat(new_stash, buffer, total_len + 1);
	free(*stash);
	*stash = new_stash;
	return (0);
}

int	get_newline(char *buffer)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	size_t	len;
	int		newline_index;

	if (!*stash)
		return (NULL);
	newline_index = get_newline(*stash);
	if (newline_index == -1)
		len = ft_strlen(*stash);
	else
		len = newline_index + 1;
	line = ft_substr(*stash, 0, len);
	if (!line)
		return (free(*stash), *stash = NULL, NULL);
	if (ft_strlen(*stash) > len)
		new_stash = ft_substr(*stash, len, ft_strlen(*stash) - len);
	else
		new_stash = NULL;
	free(*stash);
	*stash = new_stash;
	return (line);
}

int	read_and_append(int fd, char **stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		if (append_to_stash(stash, buffer) == -1)
		{
			free(buffer);
			return (-1);
		}
		if (get_newline(*stash) != -1)
			break ;
	}
	free(buffer);
	if (bytes_read < 0)
		return (-1);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_and_append(fd, &stash);
	if (bytes_read < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (!stash || ft_strlen(stash) == 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (extract_line(&stash));
}
/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/
