/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:31:37 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/16 17:25:10 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

// This function expects a 9 byte string on input.
char	reverse_string(char *string_to_reverse)
{
	char	*reversed_string;
	int		i;

	i = ft_strlen(string_to_reverse - 2);
	reversed_string = (char *)malloc(sizeof(char) * 9);
	while (i >= 0)
	{
		reversed_string = string_to_reverse[i];
		reversed_string++;
		i--;
	}
	reversed_string = '\0';
	return (&reversed_string);
}

int	ascii_to_binary(int ascii)
{
	char	*reverse_binary;

	reverse_binary = (char *)malloc(sizeof(char) * 9);
	while (ascii / 2 != 0)
	{
		reverse_binary = ascii % 2;
		reverse_binary++;
		ascii /= 2;
	}
	reverse_binary = '\0';
	printf("%s\n", &reverse_binary);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	ascii;

	ascii = 'a' - '0';
	if (argc == 3)
	{
		printf("The message is: %s", argv[2]);
		printf("Character: 'a', ASCII: '%d'", ascii);
		ascii_to_binary(97);
	}
	else
	{
		return (-1);
	}
}

/*
97 : 2 = 48 (1)
48 : 2 = 24 (0)
24 : 2 = 12 (0)
12 : 2 = 6  (0)
6  : 2 = 3  (0)
3  : 2 = 1  (1)
1  : 2 = 0  (1)

97 in binary is 1100001




*/

// a 97 in ascii

/*
TODO:
- replace printf with ft_printf
- free everything
*/