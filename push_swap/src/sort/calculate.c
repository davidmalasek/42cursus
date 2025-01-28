/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:28:46 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/28 13:08:22 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Returns cheapest number of steps to sort current number to stack_b.
 * Function recognizes situations when function grouping can be used,
 * for example rr(), ss() or rrr().
 */
int	calculate_current_cheapest_num_of_steps_to_top(t_stack *stack_a,
		t_stack *stack_b, int index_a, int index_b)
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
 * Returns:
 * t_pair.item - an index of a cheapest number in stack_a.
 * t_pair.target - an index of a number in stack_b to sort against.
 * A "cheapest number" is a number that needs the least
 * amount of steps to sort it correctly to stack_b.
 */
// TODO: handle situations when helper functions return error values.
// TODO: I can probably replace cheapest_pos and sort_Against with the struct
t_pair	calculate(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		cheapest_pos;
	int		cheapest_num_of_steps;
	int		sort_against;
	t_pair	sort_pair;

	i = stack_a->top;
	cheapest_pos = -1;
	cheapest_num_of_steps = 0;
	while (i >= 0)
	{
		if (stack_a->data[i] > stack_b->data[get_max(stack_b)]
			|| stack_a->data[i] < stack_b->data[get_min(stack_b)])
		{
			if (calculate_current_cheapest_num_of_steps_to_top(stack_a, stack_b,
					i, get_max(stack_b)) < cheapest_num_of_steps
				|| cheapest_pos == -1)
			{
				cheapest_pos = i;
				cheapest_num_of_steps = calculate_current_cheapest_num_of_steps_to_top(stack_a,
						stack_b, i, get_max(stack_b));
				sort_against = get_max(stack_b);
			}
		}
		else if (calculate_current_cheapest_num_of_steps_to_top(stack_a,
				stack_b, i, find_nln(stack_a, stack_b,
					i)) < cheapest_num_of_steps || cheapest_pos == -1)
		{
			cheapest_pos = i;
			cheapest_num_of_steps = calculate_current_cheapest_num_of_steps_to_top(stack_a,
					stack_b, i, find_nln(stack_a, stack_b, i));
			sort_against = find_nln(stack_a, stack_b, i);
		}
		i--;
	}
	sort_pair.item = cheapest_pos;
	sort_pair.target = sort_against;
	return (sort_pair);
}
