/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:03:57 by dmalasek          #+#    #+#             */
/*   Updated: 2025/01/21 21:47:50 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// TODO: Not working
int	check_input(int argc, char **argv)
{
	int		i;
	int		e;
	char	*memory[argc - 1];
	int		items_in_memory;

	items_in_memory = 0;
	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i])
			|| !is_in_int_range((long long)ft_atoi(argv[i])))
			return (0);
		e = 0;
		while (e < items_in_memory)
		{
			if (ft_strcmp(memory[e], argv[i]) == 0)
				return (0);
			e++;
		}
		memory[items_in_memory] = argv[i];
		items_in_memory++;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (!check_input(argc, argv))
		ft_putstr_fd("Error\n", 2);
}

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
*/
