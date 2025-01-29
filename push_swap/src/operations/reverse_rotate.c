/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:07:18 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/27 10:32:19 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Universal reverse_rotate function that does not print anything.
 */
void	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (is_empty(stack) || stack->top == 0)
		return ;
	temp = stack->data[0];
	i = 0;
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = temp;
}

/**
 * Shifts down all elements of stack a by 1.
 * The last element becomes the first one.
 */
void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

/**
 * Shifts down all elements of stack b by 1.
 * The last element becomes the first one.
 */
void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

/**
 * rra and rrb at the same time.
 */
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
