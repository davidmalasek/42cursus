/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:51:58 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/27 17:26:44 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_stack(t_stack *stack, const char *label)
{
	int	i;

	printf("%s: ", label);
	if (stack->top == -1)
	{
		printf("(empty)");
	}
	else
	{
		i = stack->top;
		while (i >= 0)
		{
			printf("%d ", stack->data[i]);
			i--;
		}
	}
	printf("\n");
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("\n-------------\n");
	print_stack(stack_a, "STACK A");
	print_stack(stack_b, "STACK B");
	printf("-------------\n\n");
}
