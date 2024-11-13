/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:11 by davidmalase       #+#    #+#             */
/*   Updated: 2024/11/13 17:16:11 by dmalasek         ###   ########.fr       */
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

void	append_to_stash(char **stash, char *buffer)
{
	char	*new_stash;
	size_t	total_len;

	total_len = ft_strlen(buffer);
	if (*stash)
		total_len += ft_strlen(*stash);
	new_stash = (char *)malloc(total_len + 1);
	if (!new_stash)
		return ;
	new_stash[0] = '\0';
	if (*stash)
		ft_strlcpy(new_stash, *stash, ft_strlen(*stash) + 1);
	ft_strlcat(new_stash, buffer, total_len + 1);
	free(*stash);
	*stash = new_stash;
}

int	read_and_append(int fd, char **stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		append_to_stash(stash, buffer);
		if (get_newline(*stash) != -1)
			break ;
	}
	free(buffer);
	return (bytes_read);
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	int		newline_index;

	newline_index = get_newline(*stash);
	if (newline_index != -1)
	{
		line = ft_substr(*stash, 0, newline_index + 1);
		new_stash = ft_substr(*stash, newline_index + 1, ft_strlen(*stash)
				- newline_index - 1);
		if (!new_stash)
		{
			free(line);
			return (NULL);
		}
		free(*stash);
		*stash = new_stash;
	}
	else
	{
		line = ft_substr(*stash, 0, ft_strlen(*stash));
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_and_append(fd, &stash);
	if (bytes_read < 0 || !stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (ft_strlen(stash) == 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (extract_line(&stash));
}
