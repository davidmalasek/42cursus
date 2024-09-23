/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:09:49 by davidmalase       #+#    #+#             */
/*   Updated: 2024/09/23 16:38:04 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_substr;
	size_t	i;

	if (!s)
		return (NULL);
	if ((int)start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new_substr = (char *)malloc(len + 1);
	if (!new_substr)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_substr[i] = s[start];
		i++;
		start++;
	}
	new_substr[i] = '\0';
	return (new_substr);
}

// int	main(void)
// {
// 	char *str = "Hello, world!";
// 	char *substr;

// 	substr = ft_substr(str, 7, 5);
// 	printf("Substring (7, 5): '%s'\n", substr);
// 	free(substr);

// 	// Test 2: Start beyond string length
// 	substr = ft_substr(str, 20, 5);
// 	printf("Substring (20, 5): '%s'\n", substr);
// 	free(substr);

// 	substr = ft_substr(str, 5, 10);
// 	printf("Substring (5, 10): '%s'\n", substr);
// 	free(substr);

// 	substr = ft_substr(str, 4, 0);
// 	printf("Substring (4, 0): '%s'\n", substr);
// 	free(substr);

// 	// Test 5: Null string
// 	substr = ft_substr(NULL, 0, 5);
// 	printf("Substring (NULL): '%s'\n", substr);
// 	free(substr);

// 	return (0);
// }