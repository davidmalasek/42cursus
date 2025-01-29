/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:34:35 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/29 13:52:42 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_duplicate(char *arg, char **memory, int items)
{
	int	i;

	i = 0;
	while (i < items)
	{
		if (ft_strcmp(memory[i], arg) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	process_arguments(int argc, char **argv, char **memory)
{
	int	items_in_memory;
	int	error;
	int	i;

	items_in_memory = 0;
	i = 1;
	while (i < argc)
	{
		ft_safe_atoi(argv[i], &error);
		if (!is_integer(argv[i]) || error || is_duplicate(argv[i], memory,
				items_in_memory))
			throw_error(memory, items_in_memory);
		memory[items_in_memory] = ft_strdup(argv[i]);
		if (!memory[items_in_memory])
			throw_error(memory, items_in_memory);
		items_in_memory++;
		i++;
	}
	free_memory(memory, items_in_memory);
}

void	check_input(int argc, char **argv)
{
	char	**memory;

	if (argc == 1)
		throw_error(NULL, 0);
	memory = allocate_and_validate_memory(argc);
	process_arguments(argc, argv, memory);
}

// TODO: Maybe exit(0)?