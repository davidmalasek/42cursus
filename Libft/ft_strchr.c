/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:41:58 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/16 15:13:24 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
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
// 	printf("Result: %s\n", result);
// 	printf("Result2: %s\n", result2);
// }
