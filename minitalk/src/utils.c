/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:20:16 by dmalasek          #+#    #+#             */
/*   Updated: 2025/01/21 14:37:21 by dmalasek         ###   ########.fr       */
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

char	*ft_strchr(const char *string, int character)
{
	unsigned char	unsigned_char;

	unsigned_char = (unsigned char)character;
	while (*string)
	{
		if ((unsigned char)*string == unsigned_char)
			return ((char *)string);
		string++;
	}
	if (unsigned_char == '\0')
		return ((char *)string);
	return (NULL);
}
