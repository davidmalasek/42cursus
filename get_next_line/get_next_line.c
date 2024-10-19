/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:11 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/19 15:37:35 by davidmalase      ###   ########.fr       */
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

	if (*stash == NULL)
	{
		total_len = ft_strlen(buffer);
		new_stash = (char *)malloc(total_len + 1);
		if (!new_stash)
			return ;
		new_stash[0] = '\0';
	}
	else
	{
		total_len = ft_strlen(*stash) + ft_strlen(buffer);
		new_stash = (char *)malloc(total_len + 1);
		if (!new_stash)
			return ;
		ft_strlcpy(new_stash, *stash, ft_strlen(*stash) + 1);
	}
	ft_strlcat(new_stash, buffer, total_len + 1);
	free(*stash);
	*stash = new_stash;
}

void	trim_stash(char **stash, int newline_index)
{
	char	*new_stash;
	int		i;
	int		e;

	i = 0;
	e = newline_index + 1;
	new_stash = (char *)malloc(ft_strlen(*stash) - newline_index);
	if (!new_stash)
		return ;
	while ((*stash)[e])
		new_stash[i++] = (*stash)[e++];
	new_stash[i] = '\0';
	free(*stash);
	*stash = new_stash;
}

char	*extract_line(char **stash)
{
	char	*line;
	int		newline_index;

	newline_index = get_newline(*stash);
	if (newline_index != -1)
	{
		line = ft_substr(*stash, 0, newline_index + 1);
		trim_stash(stash, newline_index);
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
	char		buffer[BUFFER_SIZE + 1];
	static char	*stash;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		append_to_stash(&stash, buffer);
		if (get_newline(stash) != -1)
			return (extract_line(&stash));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0 || stash == NULL)
		return (free(stash), stash = NULL, NULL);
	if (ft_strlen(stash) > 0)
		return (extract_line(&stash));
	return (free(stash), stash = NULL, NULL);
}
