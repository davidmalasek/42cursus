/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:51:57 by davidmalase       #+#    #+#             */
/*   Updated: 2025/02/01 13:24:20 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Allocates memory.
 */
char	**allocate_and_validate_memory(int argc)
{
	char	**memory;

	memory = (char **)malloc(sizeof(char *) * (argc - 1));
	if (!memory)
		throw_error(NULL, 0);
	return (memory);
}

/**
 * Frees memory.
 */
void	free_memory(char **memory, int items)
{
	if (!memory)
		return ;
	while (items > 0)
		free(memory[--items]);
	free(memory);
}

/**
 * Throws an error, frees the memory and exits the program.
 */
void	throw_error(char **memory, int items)
{
	ft_putstr_fd("Error\n", 2);
	free_memory(memory, items);
	exit(1);
}
