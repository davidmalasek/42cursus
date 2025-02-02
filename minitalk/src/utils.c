/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:20:16 by dmalasek          #+#    #+#             */
/*   Updated: 2025/02/02 16:18:44 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str == ' ' || *str == '\f') || (*str == '\n' || *str == '\r')
		|| (*str == '\t' || *str == '\v'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

double	ft_power(double base, int exp)
{
	if (exp == 0)
		return (1);
	if (exp < 0)
		return (1 / ft_power(base, -exp));
	return (base * ft_power(base, exp - 1));
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

/**
 * Converts 8 characters (~ 8 bits) into character according to ASCII.
 */
char	binary_to_character(char *string)
{
	int	i;
	int	ascii;

	ascii = 0;
	i = 0;
	while (i < 8)
	{
		ascii += (string[i] - '0') * ft_power(2, 7 - i);
		i++;
	}
	return ((char)ascii);
}
