/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:41:01 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/29 13:53:30 by davidmalase      ###   ########.fr       */
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

typedef struct s_pair
{
	int	item;
	int	target;
}		t_pair;

// Utils
int		is_integer(const char *str);
int		ft_safe_atoi(const char *str, int *error);

// Helper
void	print_stack(t_stack *stack, const char *label);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

// Sort
void	sort(t_stack *stack_a, t_stack *stack_b);

// Sort utils
void	repeat_for_stack(void (*f)(t_stack *stack), t_stack *stack, int times);
void	repeat_for_stacks(void (*f)(t_stack *stack_a, t_stack *stack_b),
			t_stack *stack_a, t_stack *stack_b, int times);

// Calculate
t_pair	calculate(t_stack *stack_a, t_stack *stack_b);

// Calculate utils
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		steps_to_top(t_stack *stack, int item_index);
int		find_nln(t_stack *stack_a, t_stack *stack_b, int number_index);
int		find_nbn(t_stack *stack, t_stack *target_stack, int number_index);

// Validation
void	check_input(int argc, char **argv);

// Validation utils
char	**allocate_and_validate_memory(int argc);
void	free_memory(char **memory, int items);
void	throw_error(char **memory, int items);

// Stack
t_stack	*create_stack(int capacity);
void	push_to_stack(t_stack *stack, int value);
int		pop(t_stack *stack);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);

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