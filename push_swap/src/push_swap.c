/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:03:57 by dmalasek          #+#    #+#             */
/*   Updated: 2025/02/03 10:16:24 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// #include <stdio.h>
// void	print_stacks(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	i;

// 	printf("\n-------------\n");
// 	printf("STACK A: ");
// 	if (stack_a->top == -1)
// 		printf("(empty)");
// 	else
// 	{
// 		i = stack_a->top;
// 		while (i >= 0)
// 		{
// 			printf("%d ", stack_a->data[i]);
// 			i--;
// 		}
// 	}
// 	printf("\n");
// 	printf("STACK B: ");
// 	if (stack_b->top == -1)
// 		printf("(empty)");
// 	else
// 	{
// 		i = stack_b->top;
// 		while (i >= 0)
// 		{
// 			printf("%d ", stack_b->data[i]);
// 			i--;
// 		}
// 	}
// 	printf("\n-------------\n\n");
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_input(argc, argv);
	stack_a = create_stack(argc - 1);
	stack_b = create_stack(argc - 1);
	fill_stack(stack_a, argv);
	sort(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}
