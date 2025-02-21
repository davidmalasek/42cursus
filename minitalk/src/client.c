/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:31:37 by davidmalase       #+#    #+#             */
/*   Updated: 2025/02/21 15:31:43 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/**
 * Converts an ASCII integer into 8 bit binary.
 */
char	*ascii_to_binary(int ascii)
{
	char	*binary;
	int		i;

	binary = (char *)malloc(sizeof(char) * 9);
	if (!binary)
		return (NULL);
	binary[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		if (ascii % 2)
			binary[i] = '1';
		else
			binary[i] = '0';
		i--;
		ascii /= 2;
	}
	return (binary);
}

/**
 * Frees binary variable from send_string(), prints error message and exits.
 */
void	failed_kill(char *binary)
{
	free(binary);
	ft_printf("Error: failed to send either SIGUSR1 or SIGUSR2\n");
	exit(-1);
}

/**
 * Sends string from standart input to the server using kill().
 */
void	send_string(pid_t pid, char *string)
{
	char	*binary;
	int		i;

	while (1)
	{
		binary = ascii_to_binary((int)*string);
		i = 0;
		while (binary[i] != '\0')
		{
			if (binary[i] == '1')
			{
				if (kill(pid, SIGUSR1) == -1)
					failed_kill(binary);
			}
			else if (kill(pid, SIGUSR2) == -1)
				failed_kill(binary);
			usleep(300);
			i++;
		}
		free(binary);
		if (*string == '\0')
			break ;
		string++;
	}
}

/**
 * Sends the string from standart input along with
 * null terminator to indicate the end of string.
 */
int	main(int argc, char *argv[])
{
	if (argc == 3)
		send_string(ft_atoi(argv[1]), argv[2]);
	else
	{
		ft_printf("Error: this program expects 2 arguments\n");
		exit(-1);
	}
}
