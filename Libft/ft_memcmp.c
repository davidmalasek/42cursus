/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:48:04 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/21 12:31:30 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1 = (unsigned char *)s1 + 1;
		s2 = (unsigned char *)s2 + 1;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char str1[] = "abcdef";
// 	const char str2[] = "abcdeg";
// 	const char str3[] = "abcdef";
// 	const char str4[] = "abcd";

// 	int result;

// 	result = ft_memcmp(str1, str2, 6);
// 	printf("Comparing \"%s\" and \"%s\": %d\n", str1, str2, result);

// 	result = ft_memcmp(str1, str3, 6);
// 	printf("Comparing \"%s\" and \"%s\": %d\n", str1, str3, result);

// 	result = ft_memcmp(str1, str4, 4);
// 	printf("Comparing \"%s\" and \"%s\": %d\n", str1, str4, result);

// 	result = ft_memcmp(str1, str4, 5);
// 	printf("Comparing \"%s\" and \"%s\": %d\n", str1, str4, result);

// 	return (0);
// }