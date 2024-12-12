/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:02:43 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/12 18:12:43 by davidmalase      ###   ########.fr       */
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
