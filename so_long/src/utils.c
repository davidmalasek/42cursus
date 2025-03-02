/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:02:43 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/18 17:55:29 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	size_t			length;
	size_t			i;

	length = count * size;
	i = 0;
	if (!count || !size)
		return (malloc(0));
	if (length / size != count)
		return (NULL);
	result = (unsigned char *)malloc(length);
	if (result == NULL)
		return (NULL);
	while (i < length)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}

char	**string_to_array(char *map)
{
	char	**matrix;
	int		size_x;
	int		size_y;

	if (!map)
		return (NULL);
	size_x = get_size_x(map);
	size_y = get_size_y(map);
	matrix = allocate_matrix(size_x, size_y);
	if (!matrix)
		return (NULL);
	fill_matrix(matrix, map, size_x, size_y);
	return (matrix);
}

void	free_matrix(char **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**allocate_matrix(int size_x, int size_y)
{
	char	**matrix;
	int		i;

	i = 0;
	if (size_x <= 0 || size_y <= 0)
		return (NULL);
	matrix = (char **)calloc(size_y + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	while (i < size_y)
	{
		matrix[i] = (char *)calloc(size_x + 1, sizeof(char));
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

void	fill_matrix(char **matrix, char *map, int size_x, int size_y)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (*map && row < size_y)
	{
		if (*map == '\n')
		{
			matrix[row][col] = '\0';
			row++;
			col = 0;
		}
		else if (col < size_x)
		{
			matrix[row][col] = *map;
			col++;
		}
		map++;
	}
	if (col > 0 && row < size_y)
		matrix[row][col] = '\0';
}
