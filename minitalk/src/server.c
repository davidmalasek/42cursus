/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:31:40 by davidmalase       #+#    #+#             */
/*   Updated: 2025/02/02 16:27:41 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_buffer	*g_buffer;

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_buffer != NULL)
	{
		if (g_buffer->data)
			free(g_buffer->data);
		free(g_buffer);
		g_buffer = NULL;
	}
	exit(0);
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

/**
 * Checks whether the buffer is not full.
 * If the buffer is full, it reallocates it.
 */
void	handle_buffer(void)
{
	char	*new_data;
	int		last_size;

	if (g_buffer == NULL)
		init_buffer();
	if (ft_strlen(g_buffer->data) >= (size_t)(g_buffer->size - 1))
	{
		last_size = g_buffer->size;
		new_data = (char *)malloc((last_size * 2) + 1);
		if (!new_data)
		{
			write(2, "Memory allocation failed\n", 25);
			exit(1);
		}
		ft_strcpy(new_data, g_buffer->data);
		free(g_buffer->data);
		g_buffer->data = new_data;
		g_buffer->size = (last_size * 2) + 1;
	}
}

void	handle_signal(int signal)
{
	static int	bit_index;
	static char	current_char;

	if (!g_buffer)
		init_buffer();
	if (signal == SIGUSR1)
		current_char |= (1 << (7 - bit_index));
	bit_index++;
	if (bit_index == 8)
	{
		if (ft_strlen(g_buffer->data) + 2 >= (size_t)(g_buffer->size))
			handle_buffer();
		g_buffer->data[ft_strlen(g_buffer->data)] = current_char;
		g_buffer->data[ft_strlen(g_buffer->data) + 1] = '\0';
		if (current_char == '\0')
		{
			write(1, g_buffer->data, ft_strlen(g_buffer->data));
			free(g_buffer->data);
			free(g_buffer);
			g_buffer = NULL;
		}
		current_char = 0;
		bit_index = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	signal(SIGINT, sigint_handler);
	while (1)
		pause();
}
