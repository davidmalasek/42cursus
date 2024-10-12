/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:11 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/12 17:48:28 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_newline_index(char *buffer)
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

void	shift_buffer(char *buffer, int newline_index)
{
	int		i;
	char	*original_position;

	original_position = buffer;
	i = 0;
	while (i++ < newline_index)
		buffer++;
	ft_strlcpy(original_position, buffer, 10);
}

char	*grow_line(char *line, int line_length, char *buffer, int buffer_size)
{
	char	*new_line;
	int		new_size;

	new_size = line_length + buffer_size + 1;
	new_line = malloc(new_size);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(new_line, line, new_size);
	ft_strlcat(new_line, buffer, new_size);
	free(line);
	return (new_line);
}

char	*process_buffer(char *line, char *buffer)
{
	int	newline_index;

	newline_index = get_newline_index(buffer);
	if (newline_index != -1)
	{
		shift_buffer(buffer, newline_index);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*result;

	int bytes_read, line_length = 0;
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = grow_line(line, line_length, buffer, bytes_read);
		if (!line)
			return (NULL);
		line_length += bytes_read;
		result = process_buffer(line, buffer);
		if (result)
			return (result);
	}
	if (line_length > 0)
		return (line);
	free(line);
	return (NULL);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

// 	if (close(fd) == -1)
// 	{
// 		perror("Error closing file");
// 		return (1);
// 	}

// 	return (0);
// }