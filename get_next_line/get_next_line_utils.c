/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:44 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/09 14:13:53 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (&buffer[i]);
	}
	return (NULL);
}

char	*extract_line(char *buffer, int end)
{
	char *line;
	int i;

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