/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:15:29 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/23 18:16:02 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	e;

	i = 0;
	if (*l == '\0')
		return ((char *)b);
	while (i < len && b[i] != '\0')
	{
		if (b[i] == l[0])
		{
			e = 0;
			while ((l[e] != '\0') && ((i + e) < len) && (b[i + e] == l[e]))
				e++;
			if (l[e] == '\0')
				return ((char *)&b[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char *big1 = "Hello, world!";
// 	const char *little1 = "world";
// 	size_t len1 = 12;
// 	char *result1 = strnstr(big1, little1, len1);
// 	if (result1 != NULL)
// 		printf("Test Case 1: Found '%s' in '%s'\n", little1, result1);
// 	else
// 		printf("Test Case 1: '%s' not found within first %zu characters.\n",
// 			little1, len1);
// }