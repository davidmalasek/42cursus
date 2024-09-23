/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:32:57 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/23 17:47:25 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*final_str;
	int		i;

	final_str = malloc(ft_strlen(s) + 1);
	if (!final_str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		final_str[i] = (*f)(i, s[i]);
		i++;
	}
	final_str[i] = '\0';
	return (final_str);
}

// char	test_function(unsigned int integer, char character)
// {
// 	return (character - 1);
// }

// int	main(void)
// {
// 	char test[] = "42Prague";
// 	char *res = ft_strmapi(test, test_function);

// 	printf("res: %s\n", res);
// }