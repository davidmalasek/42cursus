/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:29:31 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/28 11:30:06 by davidmalase      ###   ########.fr       */
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
int	get_max(t_stack *stack)
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
	return (max_num_index);
}

/**
 * Returns an index of currently smallest number in stack.
 */
int	get_min(t_stack *stack)
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
	return (min_num_index);
}

/**
 * Returns a number of steps it would take
 * to bring a number to the top of the stack.
 */
int	steps_to_top(t_stack *stack, int item_index)
{
	if (item_index + 1 > stack->top - item_index)
		return (stack->top - item_index);
	else
		return (item_index + 1);
}

int	find_nln(t_stack *stack_a, t_stack *stack_b, int number_index)
{
	int	i;
	int	nln;
	int	nln_index;

	i = stack_b->top;
	nln = 0;
	nln_index = -1;
	while (i >= 0)
	{
		if ((nln_index == -1 && stack_b->data[i] < stack_a->data[number_index])
			|| (stack_b->data[i] < stack_a->data[number_index]
				&& stack_b->data[i] > nln))
		{
			nln = stack_b->data[i];
			nln_index = i;
		}
		i--;
	}
	return (nln_index);
}
