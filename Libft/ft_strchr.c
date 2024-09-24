/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:41:58 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/24 18:52:09 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int character)
{
	if (string == NULL)
		return (NULL);
	while (*string)
	{
		if (*string == (char)character)
			return ((char *)string);
		string++;
	}
	if (character == '\0')
		return ((char *)string);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	string[] = "42 Prague";
// 	char	character;
// 	char	*result;
// 	char	*result2;

// 	character = ' ';
// 	result = ft_strchr(string, character);
// 	result2 = strchr(string, character);
// 	printf("Result: %string\n", result);
// 	printf("Result2: %string\n", result2);
// }
