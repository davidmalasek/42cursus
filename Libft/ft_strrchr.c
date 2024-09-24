/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:13:50 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/24 18:56:59 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	const char	*last_occurrence;

	if (str == NULL)
		return (NULL);
	last_occurrence = NULL;
	while (*str != '\0')
	{
		if (*str == (char)character)
			last_occurrence = str;
		str++;
	}
	if (character == '\0')
		return ((char *)str);
	return ((char *)last_occurrence);
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
// 	printf("Result: %str\n", result);
// 	printf("Result2: %str\n", result2);
// }