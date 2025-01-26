/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:34:35 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/26 14:23:29 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_duplicate(char *arg, char **memory, int items)
{
	int	i;

	i = 0;
	while (i < items)
		if (ft_strcmp(memory[i++], arg) == 0)
			return (1);
	return (0);
}

void	check_input(int argc, char **argv)
{
	char	*memory[argc - 1];
	int		items_in_memory;
	int		error;
	int		i;

	items_in_memory = 0;
	i = 1;
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while (i < argc)
	{
		ft_safe_atoi(argv[i], &error);
		if (!is_integer(argv[i]) || error || is_duplicate(argv[i], memory,
				items_in_memory))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		memory[items_in_memory++] = argv[i++];
	}
}

// TODO: Maybe exit(0)?