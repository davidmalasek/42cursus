/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:10:42 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/24 18:54:32 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL || src == NULL)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	if ((char *)dest < (char *)src)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char src1[] = "Hello, World!";
// 	char dest1[20];

// 	printf("Test 1 - Non-overlapping regions\n");
// 	printf("Before memmove:\n");
// 	printf("src1: %s\n", src1);
// 	memmove(dest1, src1, strlen(src1) + 1);
// 	printf("After memmove:\n");
// 	printf("dest1: %s\n\n", dest1);

// 	char src2[] = "Overlap Test";
// 	printf("Test 2 - Overlapping regions (copy forward)\n");
// 	printf("Before memmove:\n");
// 	printf("src2: %s\n", src2);
// 	memmove(src2 + 4, src2, 7);
// 	printf("After memmove:\n");
// 	printf("src2: %s\n\n", src2);

// 	char src3[] = "Overlap Test";
// 	printf("Test 3 - Overlapping regions (copy backward)\n");
// 	printf("Before memmove:\n");
// 	printf("src3: %s\n", src3);
// 	memmove(src3, src3 + 4, 7);
// 	printf("After memmove:\n");
// 	printf("src3: %s\n", src3);
// }