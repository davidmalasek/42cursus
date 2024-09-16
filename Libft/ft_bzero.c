/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:26:15 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/16 14:04:06 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	char buffer[13] = "Hello, World!";

// 	printf("Before ft_bzero: %s\n", buffer);

// 	ft_bzero(buffer, 5);

// 	printf("After ft_bzero: %s\n", buffer);

// 	printf("Buffer content after ft_bzero:\n");
// 	for (int i = 0; i < 13; i++)
// 	{
// 		if (buffer[i] == '\0')
// 			printf("\\0 ");

// 		else
// 			printf("%c ", buffer[i]);
// 	}
// 	printf("\n");
// }