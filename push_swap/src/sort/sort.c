/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:52:35 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/27 20:06:31 by davidmalase      ###   ########.fr       */
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
// ORIGINAL:
// int	steps_to_top(t_stack *stack, int item)
// {
// 	int	item_index;

// 	item_index = get_item_index(stack, item);
// 	if (item_index + 1 > stack->top - item_index)
// 		return (stack->top - item_index);
// 	else
// 		return (item_index + 1);
// }

/**
 * Returns an index to nearest lower number in stack.
 */
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
// ORIGINAL:
// int	find_nln(t_stack *stack, int number)
// {
// 	int	i;
// 	int	nln;
// 	int	nln_index;

// 	i = stack->top;
// 	nln = 0;
// 	nln_index = -1;
// 	while (i >= 0)
// 	{
// 		if ((nln_index == -1 && stack->data[i] < number)
// 			|| (stack->data[i] < number && stack->data[i] > nln))
// 		{
// 			nln = stack->data[i];
// 			nln_index = i;
// 		}
// 		i--;
// 	}
// 	return (nln_index);
// }

int	calculate_current_cheapest_num_of_steps_to_top(t_stack *stack_a,
		t_stack *stack_b, int index_a, int index_b)
{
	int	current_cheapest_num_of_steps;

	if (steps_to_top(stack_a, index_a) == steps_to_top(stack_b, index_b))
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
 * Returns an index of a cheapest number in stack_a.
 * A "cheapest number" is a number that needs the least
 * amount of steps to sort it correctly to stack_b.
 */
// TODO: handle situations when helper functions return error values.
// TODO: ERROR! it should return 8 as the cheapest num
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
		printf("For number: %d\n", current_item);
		printf("NLN: %d\n", stack_b->data[find_nln(stack_a, stack_b, i)]);
		// printf("Steps to top in STACK_A: %d\n", steps_to_top(stack_a, i));
		if (current_item > stack_b->data[get_max(stack_b)]
			|| current_item < stack_b->data[get_min(stack_b)])
		{
			if (calculate_current_cheapest_num_of_steps_to_top(stack_a, stack_b,
					i, get_max(stack_b)) < cheapest_num_of_steps
				|| cheapest_pos == -1)
			{
				cheapest_pos = i;
				cheapest_num_of_steps = calculate_current_cheapest_num_of_steps_to_top(stack_a,
						stack_b, i, get_max(stack_b));
				printf("\n*************\n");
				printf("A\n");
				printf("Cheapest number: %d\n", stack_a->data[cheapest_pos]);
				printf("Num of steps: %d\n", cheapest_num_of_steps);
				printf("*************\n\n");
			}
		}
		else if (calculate_current_cheapest_num_of_steps_to_top(stack_a,
				stack_b, i, find_nln(stack_a, stack_b,
					i)) < cheapest_num_of_steps || cheapest_pos == -1)
		{
			cheapest_pos = i;
			cheapest_num_of_steps = calculate_current_cheapest_num_of_steps_to_top(stack_a,
					stack_b, i, find_nln(stack_a, stack_b, i));
			printf("\n*************\n");
			printf("B\n");
			printf("Cheapest number: %d\n", stack_a->data[cheapest_pos]);
			printf("Num of steps: %d\n", cheapest_num_of_steps);
			printf("NLN: %d\n", stack_b->data[find_nln(stack_a, stack_b, i)]);
			printf("*************\n\n");
		}
		i--;
	}
	print_stacks(stack_a, stack_b);
	printf("Cheapest number: %d\nSteps: %d\n", stack_a->data[cheapest_pos],
		cheapest_num_of_steps);
	return (0);
}

/*
ORIGINAL:
int	calculate(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	cheapest_pos;
	int	cheapest_num_of_steps;
	int	current_item;
	int	current_cheapest_num_of_steps;

	// TODO: maybe not needed
	i = stack_a->top;
	cheapest_pos = -1;
	cheapest_num_of_steps = 0;
	while (i >= 0)
	{
		current_item = stack_a->data[i];
		printf("For number: %d\n", current_item);
		printf("Steps to top in STACK_A: %d\n", steps_to_top(stack_a,
				current_item));
		if (current_item > stack_b->data[get_max(stack_b)])
		{
			if (steps_to_top(stack_a, current_item) == steps_to_top(stack_b,
					stack_b->data[get_max(stack_b)]))
			{
				current_cheapest_num_of_steps = (steps_to_top(stack_a,
							current_item) + steps_to_top(stack_b,
							stack_b->data[get_max(stack_b)])) / 2;
			}
			else
			{
				current_cheapest_num_of_steps = steps_to_top(stack_a,
						current_item) + steps_to_top(stack_b,
						stack_b->data[get_max(stack_b)]);
			}
			current_cheapest_num_of_steps += 1;
			if (current_cheapest_num_of_steps < cheapest_num_of_steps
				|| cheapest_pos == -1)
			{
				cheapest_pos = i;
				cheapest_num_of_steps = current_cheapest_num_of_steps;
				// printf("\n*************\n");
				// printf("A\n");
				// printf("Cheapest number: %d\n", stack_a->data[cheapest_pos]);
				// printf("Num of steps: %d\n", cheapest_num_of_steps);
				// printf("*************\n\n");
			}
		}
		else if (current_item < stack_b->data[get_min(stack_b)])
		{
			if (steps_to_top(stack_a, current_item) == steps_to_top(stack_b,
					stack_b->data[get_max(stack_b)]))
			{
				current_cheapest_num_of_steps = (steps_to_top(stack_a,
							current_item) + steps_to_top(stack_b,
							stack_b->data[get_max(stack_b)])) / 2;
			}
			else
			{
				current_cheapest_num_of_steps = steps_to_top(stack_a,
						current_item) + steps_to_top(stack_b,
						stack_b->data[get_max(stack_b)]);
			}
			current_cheapest_num_of_steps += 1;
			if (current_cheapest_num_of_steps < cheapest_num_of_steps
				|| cheapest_pos == -1)
			{
				cheapest_pos = i;
				cheapest_num_of_steps = current_cheapest_num_of_steps;
				// printf("\n*************\n");
				// printf("B\n");
				// printf("Cheapest number: %d\n", stack_a->data[cheapest_pos]);
				// printf("Num of steps: %d\n", cheapest_num_of_steps);
				// printf("*************\n\n");
			}
		}
		// else if (steps_to_top(stack_a, current_item) + steps_to_top(stack_b,
		// 		find_nln(stack_b, current_item)) + 1 < cheapest_num_of_steps
		// 	|| cheapest_pos == -1)
		// TODO: need to check for above
		else
		{
			cheapest_pos = i;
			if (steps_to_top(stack_a, current_item) == steps_to_top(stack_b,
					find_nln(stack_b, current_item)))
			{
				cheapest_num_of_steps = (steps_to_top(stack_a, current_item)
						+ steps_to_top(stack_b, find_nln(stack_b,
								current_item))) / 2;
			}
			else
			{
				cheapest_num_of_steps = steps_to_top(stack_a, current_item)
					+ steps_to_top(stack_b, find_nln(stack_b, current_item));
			}
			cheapest_num_of_steps += 1;
			// printf("\n*************\n");
			// printf("C\n");
			// printf("Cheapest number: %d\n", stack_a->data[cheapest_pos]);
			// printf("Num of steps: %d\n", cheapest_num_of_steps);
			// printf("NLN: %d\n", stack_b->data[find_nln(stack_b,
			// current_item)]);
			// printf("*************\n\n");
		}
		i--;
	}
	print_stacks(stack_a, stack_b);
	printf("Cheapest number: %d\nSteps: %d\n", stack_a->data[cheapest_pos],
		cheapest_num_of_steps);
	return (0);
}
*/

/*
TODO:
before sorting, check, if there are only 3 items. If yes, no need to use the
stack_b, as explained in the article.
*/
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	// While there are more than 3 items in stack_a, push to stack_b
	// while (stack_a->top > 2)
	// {
	// }
	calculate(stack_a, stack_b);
}
