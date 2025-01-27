/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:41:01 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/27 16:58:36 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Libft
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*data;
	int	top;
	int	capacity;
}		t_stack;

// Utils
int		is_integer(const char *str);
int		ft_safe_atoi(const char *str, int *error);

// Helper
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

// Sort
void	sort(t_stack *stack_a, t_stack *stack_b);

// Input validation
void	check_input(int argc, char **argv);

// Stack
t_stack	*create_stack(int capacity);
void	push_to_stack(t_stack *stack, int value);
int		pop(t_stack *stack);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

// Stack utils
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
void	fill_stack(t_stack *stack, char **argv);

// Operations
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

#endif