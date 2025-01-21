/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:08:00 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/21 20:08:25 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int	ft_safe_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str == ' ' || *str == '\f') || (*str == '\n' || *str == '\r')
		|| (*str == '\t' || *str == '\v'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (sign == 1 && result > MAX_INT)
			return (MAX_INT);
		if (sign == -1 && -result < MIN_INT)
			return (MIN_INT);
		str++;
	}
	return ((int)(result * sign));
}
