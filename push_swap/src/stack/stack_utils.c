/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:22:39 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/26 14:22:46 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_full(t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}
/**
 * Fills stack with int arguments from input.
 * Automatically skips 1st parameter - ./push_swap
 */
void	fill_stack(t_stack *stack, char **argv)
{
	argv++;
	while (*argv)
	{
		push_to_stack(stack, ft_atoi(*argv));
		argv++;
	}
}

/*
TODO:
- check usage of functions above
*/