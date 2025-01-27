/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:03:57 by dmalasek          #+#    #+#             */
/*   Updated: 2025/01/27 17:41:06 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_input(argc, argv);
	stack_a = create_stack(argc - 1);
	stack_b = create_stack(argc - 1);
	fill_stack(stack_a, argv);
	sort(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}

/*
TODO:
- remove printf everywhere
*/