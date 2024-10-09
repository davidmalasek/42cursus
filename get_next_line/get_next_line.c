/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:11 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/09 14:15:01 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	buffer[BUFFER_SIZE];
	int			i;
	char		*newline;

	i = 0;
	newline = find_newline(buffer);
	if (newline != NULL)
		return (extract_line(buffer, newline - buffer)); // Line up to '\n'
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
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
	printf("%s", get_next_line(0));
}