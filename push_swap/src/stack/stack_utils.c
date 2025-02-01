/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:22:39 by davidmalase       #+#    #+#             */
/*   Updated: 2025/02/01 13:22:20 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Returns 1 if stack is full (reached it's capacity).
 * Returns 0 if the stack is not full.
 */
int	is_full(t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

/**
 * Returns 1 if stack if empty.
 * Returns 0 if stack is not empty.
 */
int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

/**
 * Fills stack with int arguments from input.
 * Automatically skips 1st parameter - ./push_swap
 *
 * IMPORTANT!
 * Design of this project expects top at end of the stack array.
 */
void	fill_stack(t_stack *stack, char **argv)
{
	int	i;

	stack->top = -1;
	i = 1;
	while (argv[i])
		i++;
	i--;
	while (i > 0)
	{
		push_to_stack(stack, atoi(argv[i]));
		i--;
	}
}
