/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:52:35 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/27 14:07:09 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Returns an index of an item in a stack.
 */
int	get_item_index(t_stack *stack, int item)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->data[i] == item)
			return (i);
		i--;
	}
	return (-1);
}

/**
 * Returns an index of currently largest number in stack.
 */
int	get_current_max(t_stack *stack)
{
	int	i;
	int	max_num;
	int	max_num_index;

	i = stack->top;
	max_num = 0;
	max_num_index = -1;
	while (i >= 0)
	{
		if (max_num_index == -1 || stack->data[i] > max_num)
		{
			max_num = stack->data[i];
			max_num_index = i;
		}
		i--;
	}
	return (i);
}

/**
 * Returns an index of currently smallest number in stack.
 */
int	get_current_min(t_stack *stack)
{
	int	i;
	int	min_num;
	int	min_num_index;

	i = stack->top;
	min_num = 0;
	min_num_index = -1;
	while (i >= 0)
	{
		if (min_num_index == -1 || stack->data[i] < min_num)
		{
			min_num = stack->data[i];
			min_num_index = i;
		}
		i--;
	}
	return (i);
}

/**
 * Returns a number of steps it would take
 * to bring a number to the top of the stack.
 */
int	steps_to_top(t_stack *stack, int item)
{
	int	item_index;

	item_index = get_item_index(stack, item);
	// printf("Item: %d\n", item);
	// printf("From top steps: %d\n", stack->top - item_index);
	// printf("From bottom steps: %d\n", item_index + 1);
	if (item_index + 1 > stack->top - item_index)
		return (stack->top - item_index);
	else
		return (item_index + 1);
}

/**
 * Returns an index to nearest lower number in stack_b.
 */
int	find_nln(t_stack *stack_b, int number)
{
	int	i;
	int	nln;
	int	nln_index;

	i = stack_b->top;
	nln = 0;
	nln_index = -1;
	while (i >= 0)
	{
		if ((nln_index == -1 || nln > stack_b->data[i])
			&& stack_b->data[i] < number)
		{
			nln = stack_b->data[i];
			nln_index = i;
		}
		i--;
	}
	// printf("\nNumber: %d\n", number);
	// printf("NLN: %d\n", nln);
	// printf("NLN index: %d\n", nln_index);
	return (nln_index);
}

/**
 * Returns an index of a cheapest number in stack_a.
 */
// TODO: handle situations when helper functions return error values.
int	calculate(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	cheapest_pos;
	int	cheapest_num_of_steps;
	int	current_item;

	i = stack_a->top;
	cheapest_pos = -1;
	cheapest_num_of_steps = 0;
	while (i >= 0)
	{
		current_item = stack_a->data[i];
		// If current number is the new min/max in stack_b.
		if (current_item > get_current_max(stack_b))
		{
			printf("%d is bigger than curr max %d\n", current_item,
				get_current_max(stack_b));
			if (steps_to_top(stack_a, current_item) + steps_to_top(stack_b,
					get_current_max(stack_b)) + 1 < cheapest_num_of_steps
				&& cheapest_pos != -1)
			{
				cheapest_pos = i;
				cheapest_num_of_steps = steps_to_top(stack_a, current_item)
					+ steps_to_top(stack_b, get_current_max(stack_b)) + 1;
			}
		}
		else if (current_item < get_current_min(stack_b))
		{
			printf("%d is smaller than curr min %d\n", current_item,
				get_current_min(stack_b));
			if (steps_to_top(stack_a, current_item) + steps_to_top(stack_b,
					get_current_min(stack_b)) + 1 < cheapest_num_of_steps
				&& cheapest_pos != -1)
			{
				cheapest_pos = i;
				cheapest_num_of_steps = steps_to_top(stack_a, current_item)
					+ steps_to_top(stack_b, get_current_min(stack_b)) + 1;
			}
		}
		else if (steps_to_top(stack_a, current_item) + steps_to_top(stack_b,
				find_nln(stack_b, current_item)) + 1 < cheapest_num_of_steps
			|| cheapest_pos == -1)
		{
			printf("No\n");
			cheapest_pos = i;
			cheapest_num_of_steps = steps_to_top(stack_a, current_item)
				+ steps_to_top(stack_b, find_nln(stack_b, current_item)) + 1;
		}
		i--;
	}
	print_stacks(stack_a, stack_b);
	printf("Cheapest number: %d\nSteps: %d\n", stack_a->data[cheapest_pos],
		cheapest_num_of_steps);
	return (0);
}

/*
TODO:
before sorting, check, if there are only 3 items. If yes, no need to use the
stack_b, as explained in the article.
*/
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	// While there are more than 3 items in stack_a, push to stack_b
	// while (stack_a->top > 2)
	// {
	// }
	calculate(stack_a, stack_b);
}
