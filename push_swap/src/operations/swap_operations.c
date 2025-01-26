/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:03:38 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/26 15:22:55 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Swaps the first 2 elements at the top of stack a.
 * Does nothing if there is only one or no elements.
 */
void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->top == -1 || stack_a->top == 0)
		return ;
	temp = stack_a->data[0];
	stack_a->data[0] = stack_a->data[1];
	stack_a->data[1] = temp;
	write(1, "sa\n", 3);
}

/**
 * Swaps the first 2 elements at the top of stack b.
 * Does nothing if there is only one or no elements.
 */
void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->top == -1 || stack_b->top == 0)
		return ;
	temp = stack_b->data[0];
	stack_b->data[0] = stack_b->data[1];
	stack_b->data[1] = temp;
	write(1, "sb\n", 3);
}
/**
 * sa and sb at the same time.
 */
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
