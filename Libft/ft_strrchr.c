/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:13:50 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/21 12:32:28 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurence;

	last_occurence = 0;
	while (*s)
	{
		if (*s == (char)c)
			last_occurence = (char *)s;
		s++;
	}
	if (c == '\0')
		last_occurence = (char *)s;
	return (last_occurence);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char string[] = "42 Prague Praha";
// 	char character;
// 	char *result;
// 	char *result2;

// 	character = ' ';
// 	result = ft_strrchr(string, character);
// 	result2 = strrchr(string, character);
// 	printf("Result: %s\n", result);
// 	printf("Result2: %s\n", result2);
// }