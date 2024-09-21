/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:19:58 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/21 12:31:38 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return ((void *)(&((char *)s)[i]));
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char str[] = "Hello, World!";
// 	char target = 'W';
// 	char *result;

// 	result = ft_memchr(str, target, sizeof(str));
// 	if (result)
// 		printf("Found '%c' at position %ld\n", target, (long)(result - str));
// 	else
// 		printf("Character '%c' not found\n", target);

// 	target = 'z';
// 	result = ft_memchr(str, target, sizeof(str));
// 	if (result)
// 		printf("Found '%c' at position %ld\n", target, (long)(result - str));
// 	else
// 		printf("Character '%c' not found\n", target);
// }
