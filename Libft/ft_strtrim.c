/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:38:26 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/23 16:24:49 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size_for_alloc(char const *s1, char const *set)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (!ft_strchr(set, s1[i]))
			size++;
		i++;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final_str;
	int		i;
	int		e;

	final_str = malloc(get_size_for_alloc(s1, set) * sizeof(char) + 1);
	if (!final_str)
		return (NULL);
	i = 0;
	e = 0;
	while (s1[i] != '\0')
	{
		if (!ft_strchr(set, s1[i]))
			final_str[e++] = s1[i];
		i++;
	}
	final_str[e] = '\0';
	return (final_str);
}

// int	main(void)
// {
// 	char s1[] = "  delete + it- from he  ree  ";
// 	char set[] = " +-";
// 	char *result = ft_strtrim(s1, set);
// 	printf("Result: '%s'\n", result);
// }