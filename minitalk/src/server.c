/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:31:40 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/20 18:17:27 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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

/**
 * Prints decoded string (from binary to ASCII).
 */
void	print_string(char *string)
{
	char	*part;
	int		i;
	char	output;

	i = 0;
	part = (char *)malloc(sizeof(char) * 8);
	if (!part)
		return ;
	while (*string)
	{
		part[i] = *string;
		i++;
		if (ft_strlen(part) == 8)
		{
			i = 0;
			output = binary_to_character(part);
			write(1, &output, 1);
		}
		string++;
	}
	free(part);
}

int	main(void)
{
	// struct sigaction	action;
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
	}
}

/*
- I think it should store all the bits in one long string

*/