/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:48:15 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/28 12:42:38 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	repeat_for_stack(void (*f)(t_stack *stack), t_stack *stack, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		(*f)(stack);
		i++;
	}
}

void	repeat_for_stacks(void (*f)(t_stack *stack_a, t_stack *stack_b),
		t_stack *stack_a, t_stack *stack_b, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		(*f)(stack_a, stack_b);
		i++;
	}
}
