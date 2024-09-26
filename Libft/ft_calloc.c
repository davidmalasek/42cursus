/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:49:47 by davidmalase       #+#    #+#             */
/*   Updated: 2024/09/26 11:33:38 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	total_size;
	int	*allocated_mem;

	total_size = count * size;
	if (!count || !size)
		return (malloc(0));
	else
		allocated_mem = malloc(total_size);
	if (!allocated_mem)
		return (NULL);
	ft_memset(allocated_mem, 0, total_size);
	return (allocated_mem);
}
