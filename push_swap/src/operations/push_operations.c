/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:04:13 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/26 15:58:04 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Takes the first element at the top of b and puts it at the top of a.
 * Does nothing if b is empty.
 */
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_b))
		return ;
	push_to_stack(stack_a, pop(stack_b));
	write(1, "pa\n", 3);
}

/**
 * Takes the first element at the top of a and puts it at the top of b.
 * Does nothing if a is empty.
 */
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_a))
		return ;
	push_to_stack(stack_b, pop(stack_a));
	write(1, "pb\n", 3);
}
