/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:48:15 by davidmalase       #+#    #+#             */
/*   Updated: 2025/02/01 13:21:14 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Returns cheaper rotation times
 * stack->top - indexes.item -> rotate
 * indexes.item + 1 -> reverse rotate
 */
int	get_rotation_times(t_stack *stack, t_pair indexes)
{
	int	times;

	if (indexes.item + 1 > stack->top - indexes.item)
		times = stack->top - indexes.item;
	else
		times = indexes.item + 1;
	return (times);
}

/**
 * Applies the function to the stack specified amout of times.
 */
void	repeat_for_stack(void (*f)(t_stack *stack), t_stack *stack, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		(*f)(stack);
		i++;
	}
}

/**
 * Applies the function to the stacks specified amout of times.
 */
void	repeat_for_stacks(void (*f)(t_stack *stack_a, t_stack *stack_b),
		t_stack *stack_a, t_stack *stack_b, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		(*f)(stack_a, stack_b);
		i++;
	}
}

/**
 * Handles rotations relevant to original_stack - inherited from sort_item().
 */
void	handle_rotations_for_original_stack(t_stack *original_stack,
		t_pair indexes, int reverse)
{
	int	times;

	times = get_rotation_times(original_stack, indexes);
	if (indexes.item + 1 > original_stack->top - indexes.item)
	{
		if (reverse)
			repeat_for_stack(rb, original_stack, times);
		else
			repeat_for_stack(ra, original_stack, times);
	}
	else
	{
		if (reverse)
			repeat_for_stack(rrb, original_stack, times);
		else
			repeat_for_stack(rra, original_stack, times);
	}
}

/**
 * Handles rotations relevant to target_stack - inherited from sort_item().
 */
void	handle_rotations_for_target_stack(t_stack *target_stack, t_pair indexes,
		int reverse)
{
	if (indexes.target + 1 > target_stack->top - indexes.target)
	{
		if (reverse)
			repeat_for_stack(ra, target_stack, target_stack->top
				- indexes.target);
		else
			repeat_for_stack(rb, target_stack, target_stack->top
				- indexes.target);
	}
	else
	{
		if (reverse)
			repeat_for_stack(rra, target_stack, indexes.target + 1);
		else
			repeat_for_stack(rrb, target_stack, indexes.target + 1);
	}
}
