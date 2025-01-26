/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:31:40 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/26 12:04:22 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_buffer	*g_buffer;

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
 * Checks whether the buffer is not full.
 * If the buffer is full, it reallocates it.
 */
void	handle_buffer(void)
{
	char	*new_data;
	int		last_size;

	if (ft_strlen(g_buffer->data) == (size_t)g_buffer->size)
	{
		last_size = g_buffer->size;
		new_data = (char *)malloc(last_size * 2);
		if (!new_data)
		{
			write(2, "Memory allocation failed\n", 25);
			exit(1);
		}
		ft_strcpy(new_data, g_buffer->data);
		free(g_buffer->data);
		g_buffer->data = new_data;
		g_buffer->size = last_size * 2;
	}
}

/**
 * Initializes buffer to starting size.
 */
void	init_buffer(void)
{
	g_buffer = malloc(sizeof(t_buffer));
	if (!g_buffer)
	{
		write(2, "Memory allocation failed\n", 25);
		exit(1);
	}
	g_buffer->data = (char *)malloc(1025);
	if (!g_buffer->data)
	{
		write(2, "Memory allocation failed\n", 25);
		exit(1);
	}
	g_buffer->size = 1025;
	g_buffer->data[0] = '\0';
}

void	handle_signal(int signal)
{
	int			len;
	static int	bit_index;
	static char	current_char;

	bit_index = 0;
	current_char = 0;
	if (signal == SIGUSR1)
		current_char |= (1 << (7 - bit_index));
	bit_index++;
	if (bit_index == 8)
	{
		handle_buffer();
		len = ft_strlen(g_buffer->data);
		g_buffer->data[len] = current_char;
		g_buffer->data[len + 1] = '\0';
		if (current_char == '\0')
		{
			write(1, g_buffer->data, len);
			g_buffer->data[0] = '\0';
		}
		current_char = 0;
		bit_index = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	init_buffer();
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
}
