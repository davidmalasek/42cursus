/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:45:10 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/26 14:21:39 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Works as ordinary ft_atoi and returns an
 * error if the number is larger of smaller than int range.
 */
int	ft_safe_atoi(const char *str, int *error)
{
	long	result;
	int		positive;

	positive = 1;
	result = 0;
	*error = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			positive = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((result * positive) > 2147483647 || (result * positive) <
			-2147483648)
			return (*error = 1, 0);
		str++;
	}
	if (*str != '\0')
		*error = 1;
	return ((int)(result * positive));
}

int	is_integer(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
