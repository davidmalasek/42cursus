/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:07:18 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/26 15:22:13 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Shifts down all elements of stack a by 1.
 * The last element becomes the first one.
 */
void	rra(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (is_empty(stack_a) || stack_a->top == 0)
		return ;
	temp = stack_a->data[stack_a->top];
	i = stack_a->top;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = temp;
	write(1, "rra\n", 4);
}

/**
 * Shifts down all elements of stack b by 1.
 * The last element becomes the first one.
 */
void	rrb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (is_empty(stack_b) || stack_b->top == 0)
		return ;
	temp = stack_b->data[stack_b->top];
	i = stack_b->top;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[0] = temp;
	write(1, "rrb\n", 4);
}

/**
 * rra and rrb at the same time.
 */
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
