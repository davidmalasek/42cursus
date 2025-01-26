/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:14:14 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/26 14:21:36 by davidmalase      ###   ########.fr       */
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
	int	value;

	if (is_empty(stack))
		return (-1);
	value = stack->data[stack->top];
	stack->top--;
	return (value);
}

int	peek(t_stack *stack)
{
	if (is_empty(stack))
		return (-1);
	return (stack->data[stack->top]);
}

void	free_stack(t_stack *stack)
{
	free(stack->data);
	free(stack);
}
