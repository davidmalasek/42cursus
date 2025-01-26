/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:05:07 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/26 15:22:35 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Shifts up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (is_empty(stack_a) || stack_a->top == 0)
		return ;
	temp = stack_a->data[0];
	i = 0;
	while (i < stack_a->top)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->data[stack_a->top] = temp;
	write(1, "ra\n", 3);
}

/**
 * Shifts up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void	rb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (is_empty(stack_b) || stack_b->top == 0)
		return ;
	temp = stack_b->data[0];
	i = 0;
	while (i < stack_b->top)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->data[stack_b->top] = temp;
	write(1, "rb\n", 3);
}

/**
 * ra and rb at the same time.
 */
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
