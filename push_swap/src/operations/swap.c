/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:03:38 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/29 13:15:16 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Universal swap function that does not print anything.
 */
void	swap(t_stack *stack)
{
	int	temp;

	if (stack->top == -1 || stack->top == 0)
		return ;
	temp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = temp;
}

/**
 * Swaps the first 2 elements at the top of stack a.
 * Does nothing if there is only one or no elements.
 */
void	sa(t_stack *stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

/**
 * Swaps the first 2 elements at the top of stack b.
 * Does nothing if there is only one or no elements.
 */
void	sb(t_stack *stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

/**
 * sa and sb at the same time.
 */
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
