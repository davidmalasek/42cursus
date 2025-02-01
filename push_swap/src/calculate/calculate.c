/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:28:46 by davidmalase       #+#    #+#             */
/*   Updated: 2025/02/01 13:20:20 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Returns cheapest number of steps to sort current number to stack_b.
 * Function recognizes situations when function grouping can be used,
 * for example rr(), ss() or rrr().
 */
int	get_steps(t_stack *stack_a, t_stack *stack_b, int index_a, int index_b)
{
	int	current_cheapest_num_of_steps;

	if ((steps_to_top(stack_a, index_a) == steps_to_top(stack_b, index_b))
		&& ((stack_a->top - index_a == stack_b->top - index_b)
			|| (index_a == index_b)))
	{
		current_cheapest_num_of_steps = (steps_to_top(stack_a, index_a)
				+ steps_to_top(stack_b, index_b)) / 2;
	}
	else
	{
		current_cheapest_num_of_steps = steps_to_top(stack_a, index_a)
			+ steps_to_top(stack_b, index_b);
	}
	return (current_cheapest_num_of_steps + 1);
}

/**
 * Returns index of cheapest position in stack_b to place item from stack_a.
 */
int	calculate_target_position(t_stack *stack_a, t_stack *stack_b, int index)
{
	if (stack_a->data[index] > stack_b->data[get_max(stack_b)]
		|| stack_a->data[index] < stack_b->data[get_min(stack_b)])
		return (get_max(stack_b));
	else
		return (find_nln(stack_a, stack_b, index));
}

/**
 * Returns:
 * t_pair.item - an index of a cheapest number in stack_a.
 * t_pair.target - an index of a number in stack_b to sort against.
 * A "cheapest number" is a number that needs the least
 * amount of steps to sort it correctly to stack_b.
 */

t_pair	calculate(t_stack *st_a, t_stack *st_b)
{
	int		i;
	int		cheapest_steps;
	t_pair	pair;

	i = st_a->top + 1;
	pair.item = -1;
	cheapest_steps = 0;
	while (--i >= 0)
	{
		if (get_steps(st_a, st_b, i, get_max(st_b)) < cheapest_steps
			|| pair.item == -1)
		{
			pair.item = i;
			cheapest_steps = get_steps(st_a, st_b, i, get_max(st_b));
			pair.target = calculate_target_position(st_a, st_b, i);
		}
		else if (get_steps(st_a, st_b, i, find_nln(st_a, st_b,
					i)) < cheapest_steps || pair.item == -1)
		{
			pair.item = i;
			cheapest_steps = get_steps(st_a, st_b, i, find_nln(st_a, st_b, i));
			pair.target = calculate_target_position(st_a, st_b, i);
		}
	}
	return (pair);
}
