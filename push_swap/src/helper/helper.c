/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:51:58 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/26 14:54:53 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		printf("%d ", stack->data[i]);
		i++;
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("\n-------------\n");
	printf("STACK A:\n");
	print_stack(stack_a);
	printf("\n");
	printf("STACK B:\n");
	print_stack(stack_b);
	printf("\n-------------\n");
}