/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:52:35 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/28 20:20:17 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// TODO: fix naming
// fix when using the function the other way around (from stack_b to stack_a),
// it incorrectly prints the operations.
void	sort_item(t_stack *original_stack, t_stack *target_stack,
		t_pair indexes)
{
	int	times;

	// If is cheaper to rotate
	if (indexes.item + 1 > original_stack->top - indexes.item)
		times = original_stack->top - indexes.item;
	// If is cheaper to reverse rotate
	else
		times = indexes.item + 1;
	if (steps_to_top(original_stack, indexes.item) == steps_to_top(target_stack,
			indexes.target))
	{
		// If they have the same relative distance from top
		if ((original_stack->top - indexes.item == target_stack->top
				- indexes.target))
			repeat_for_stacks(rr, original_stack, target_stack, times);
		// If they have the same distance from bottom
		else if (indexes.item == indexes.target)
			repeat_for_stacks(rrr, original_stack, target_stack, times);
	}
	else
	{
		// For original_stack
		if (indexes.item + 1 > original_stack->top - indexes.item)
			repeat_for_stack(ra, original_stack, times);
		else
			repeat_for_stack(rra, original_stack, times);
		// For target_stack
		if (indexes.target + 1 > target_stack->top - indexes.target)
			repeat_for_stack(rb, target_stack, target_stack->top
				- indexes.target);
		else
			repeat_for_stack(rrb, target_stack, indexes.target + 1);
	}
}

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
		sort_item(stack_b, stack_a, pair);
		pa(stack_a, stack_b);
	}
}

void	final_sort(t_stack *stack_a)
{
	if (get_min(stack_a) + 1 > stack_a->top - get_min(stack_a))
		repeat_for_stack(ra, stack_a, stack_a->top - get_min(stack_a));
	else
		repeat_for_stack(rra, stack_a, get_min(stack_a) + 1);
}

/*
TODO:
before sorting, check, if there are only 3 items. If yes, no need to use the
stack_b, as explained in the article.
*/
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_pair	calculate_value;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	// While there are more than 3 items in stack_a, push to stack_b
	while (stack_a->top > 2)
	{
		calculate_value = calculate(stack_a, stack_b);
		sort_item(stack_a, stack_b, calculate_value);
		pb(stack_a, stack_b);
	}
	sort_stack_a(stack_a);
	sort_to_stack_a(stack_a, stack_b);
	final_sort(stack_a);
}
