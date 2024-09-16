/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:13:50 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/16 15:18:33 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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