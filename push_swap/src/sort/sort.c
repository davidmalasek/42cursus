/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:52:35 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/28 13:13:48 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// TODO: consider merging this with the calulate functions?
void	move_item_to_top(void (*f)(t_stack *stack), t_stack *stack, int index)
{
	if (index + 1 > stack->top - index)
		repeat_for_stack((*f), stack, stack->top - index);
	else
		repeat_for_stack((*f), stack, index + 1);
}

// TODO: doesnt work
void	sort_item(t_stack *stack_a, t_stack *stack_b, t_pair indexes)
{
	int	times;

	if (indexes.item + 1 > stack_a->top - indexes.item)
		times = stack_a->top - indexes.item;
	else
		times = indexes.item + 1;
	if (steps_to_top(stack_a, indexes.item) == steps_to_top(stack_b,
			indexes.target))
	{
		if ((stack_a->top - indexes.item == stack_b->top - indexes.target))
			repeat_for_stacks(rr, stack_a, stack_b, times);
		else if (indexes.item == indexes.target)
			repeat_for_stacks(rrr, stack_a, stack_b, times);
	}
	else
	{
		// For stack_a
		if (indexes.item + 1 > stack_a->top - indexes.item)
			repeat_for_stack(rra, stack_a, times);
		else
			repeat_for_stack(ra, stack_a, times);
		// For stack_b
		if (indexes.target + 1 > stack_b->top - indexes.target)
			repeat_for_stack(rrb, stack_a, times);
		else
			repeat_for_stack(rb, stack_a, times);
	}
	pb(stack_a, stack_b);
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
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// While there are more than 3 items in stack_a, push to stack_b
	while (stack_a->top > 2)
	{
		calculate_value = calculate(stack_a, stack_b);
		sort_item(stack_a, stack_b, calculate_value);
	}
}
