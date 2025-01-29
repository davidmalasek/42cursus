/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:05:07 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/27 10:34:45 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Universal rotate function that does not print anything.
 */
void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (is_empty(stack) || stack->top == 0)
		return ;
	temp = stack->data[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = temp;
}

/**
 * Shifts up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

/**
 * Shifts up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

/**
 * ra and rb at the same time.
 */
// TODO: This will not works since ra and rb will print on their own.
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
