/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:31:40 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/21 15:45:10 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

// 8 bits + null terminator
char	g_buffer[9];

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
 * Resets buffer after it was filled with 8 bits.
 */
void	reset_buffer(void)
{
	int	i;

	i = 0;
	while (i < 9)
		g_buffer[i++] = '\0';
}

/**
 * Handles incoming signals,
	accumulates bits and prints corresponding character.
 */
void	print_decoded_character(int signal)
{
	char	*index;
	char	output;

	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		index = ft_strchr(g_buffer, '\0');
		if (signal == SIGUSR1)
			*index = '1';
		else if (signal == SIGUSR2)
			*index = '0';
		*++index = '\0';
	}
	if (ft_strlen(g_buffer) == 8)
	{
		output = binary_to_character(g_buffer);
		write(1, &output, 1);
		reset_buffer();
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	g_buffer[0] = '\0';
	signal(SIGUSR1, print_decoded_character);
	signal(SIGUSR2, print_decoded_character);
	while (1)
		pause();
}
