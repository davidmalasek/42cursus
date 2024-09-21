/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:15:29 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/21 12:32:58 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	e;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			e = 0;
			while (little[e] != '\0' && (i + e) < len && big[i
				+ e] == little[e])
				e++;
			if (little[e] == '\0')
				return ((char *)&big[i]);
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