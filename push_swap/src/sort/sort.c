/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:52:35 by davidmalase       #+#    #+#             */
/*   Updated: 2025/02/01 13:10:45 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Rotates original stack and target stack in order to bring items
 * that resulted as "cheapest" to the top.
 * If reverse = 1, function will print operations according to sorting
 * from stack_b to stack_a.
 */
void	sort_item(t_stack *original_stack, t_stack *target_stack,
		t_pair indexes, int reverse)
{
	int	times;

	times = get_rotation_times(original_stack, indexes);
	if (steps_to_top(original_stack, indexes.item) == steps_to_top(target_stack,
			indexes.target))
	{
		if ((original_stack->top - indexes.item == target_stack->top
				- indexes.target))
			repeat_for_stacks(rr, original_stack, target_stack, times);
		else if (indexes.item == indexes.target)
			repeat_for_stacks(rrr, original_stack, target_stack, times);
	}
	else
	{
		handle_rotations_for_original_stack(original_stack, indexes, reverse);
		handle_rotations_for_target_stack(target_stack, indexes, reverse);
	}
}

/**
 * Sorts stack_a since there are only 3 items.
 */
void	sort_stack_a(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	while (!is_sorted(stack_a))
	{
		top = stack_a->data[stack_a->top];
		middle = stack_a->data[stack_a->top - 1];
		bottom = stack_a->data[stack_a->top - 2];
		if (top > bottom && middle > top)
			rra(stack_a);
		else if (top > bottom && bottom > middle)
			ra(stack_a);
		else
			sa(stack_a);
	}
}

/**
 * Pushes items from stack_a to corresponding location in
 * stack_a.
 */
void	sort_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	t_pair	pair;

	while (stack_b->top != -1)
	{
		pair.item = stack_b->top;
		if (find_nbn(stack_b, stack_a, stack_b->top) == -1)
			pair.target = get_min(stack_a);
		else
			pair.target = find_nbn(stack_b, stack_a, stack_b->top);
		sort_item(stack_b, stack_a, pair, 1);
		pa(stack_a, stack_b);
	}
}

/**
 * Continuously rotates stack_a in order to achieve
 * ascending order of items.
 */
void	final_sort(t_stack *stack_a)
{
	if (get_min(stack_a) + 1 > stack_a->top - get_min(stack_a))
		repeat_for_stack(ra, stack_a, stack_a->top - get_min(stack_a));
	else
		repeat_for_stack(rra, stack_a, get_min(stack_a) + 1);
}

/**
 * Handles sorting. Acts according to number of
 * items in the stack_a.
 */
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_pair	calculate_value;

	if (stack_a->top == 0 || (stack_a->top == 1 && is_sorted(stack_a)))
		return ;
	else if (stack_a->top == 1 && !is_sorted(stack_a))
		ra(stack_a);
	else if (stack_a->top == 2)
		sort_stack_a(stack_a);
	else if (!is_sorted(stack_a))
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		while (stack_a->top > 2)
		{
			calculate_value = calculate(stack_a, stack_b);
			sort_item(stack_a, stack_b, calculate_value, 0);
			pb(stack_a, stack_b);
		}
		sort_stack_a(stack_a);
		sort_to_stack_a(stack_a, stack_b);
		final_sort(stack_a);
	}
}
