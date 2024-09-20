/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:49:47 by davidmalase       #+#    #+#             */
/*   Updated: 2024/09/20 13:06:47 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	int	total_size;
	int	*allocated_mem;

	total_size = count * size;
	allocated_mem = malloc(total_size);
	memset(allocated_mem, 0, total_size);
	return (allocated_mem);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		*arr;
// 	size_t	count;
// 	size_t	size;

// 	count = 5;
// 	size = sizeof(int);
// 	arr = ft_calloc(count, size);
// 	if (arr == NULL)
// 	{
// 		printf("Memory allocation failed!\n");
// 		return (1);
// 	}
// 	printf("Memory allocation successful.\n");
// 	for (size_t i = 0; i < count; i++)
// 		printf("arr[%zu] = %d\n", i, arr[i]);
// 	free(arr);
// 	return (0);
// }
