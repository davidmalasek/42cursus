/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:14:14 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/29 13:15:45 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->data = malloc(sizeof(int) * capacity);
	stack->top = -1;
	stack->capacity = capacity;
	return (stack);
}

void	push_to_stack(t_stack *stack, int value)
{
	if (is_full(stack))
		return ;
	stack->top++;
	stack->data[stack->top] = value;
}

int	pop(t_stack *stack)
{
	if (is_empty(stack))
		return (-1);
	return (stack->data[stack->top--]);
}

/**
 * Returns 1 if stack is sorted (ascending), otherwise
 * returns 0.
 */
int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i > 0)
	{
		if (stack->data[i] > stack->data[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->data);
	free(stack_b->data);
	free(stack_a);
	free(stack_b);
}
