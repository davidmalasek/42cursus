/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:52:35 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/29 18:39:13 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	printf("Times: %d\n", times);
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
		if (indexes.item + 1 > original_stack->top - indexes.item)
			if (reverse)
				repeat_for_stack(rb, original_stack, times);
			else
				repeat_for_stack(ra, original_stack, times);
		else if (reverse)
			repeat_for_stack(rrb, original_stack, times);
		else
			repeat_for_stack(rra, original_stack, times);
		if (indexes.target + 1 > target_stack->top - indexes.target)
			repeat_for_stack(rb, target_stack, target_stack->top
				- indexes.target);
		else if (reverse)
			repeat_for_stack(rra, target_stack, indexes.target + 1);
		else
			repeat_for_stack(rrb, target_stack, indexes.target + 1);
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
		print_stacks(stack_a, stack_b);
		pair.item = stack_b->top;
		if (find_nbn(stack_b, stack_a, stack_b->top) == -1)
		{
			pair.target = get_min(stack_a);
			printf("aaa");
		}
		else
		{
			pair.target = find_nbn(stack_b, stack_a, stack_b->top);
			printf("bbb");
		}
		printf("For number %d found %d\n", stack_b->data[stack_b->top],
			stack_a->data[pair.target]);
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
