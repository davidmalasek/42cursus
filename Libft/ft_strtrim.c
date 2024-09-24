/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:38:26 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/24 17:39:35 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO: this one should only check at start and end, redo this.

int	ft_get_size_for_alloc(char const *s1, char const *set)
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

	final_str = malloc(ft_get_size_for_alloc(s1, set) * sizeof(char) + 1);
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
// 	char s1[] = "lorem ipsum dolor sit am";
// 	char set[] = " +-";
// 	char *result = ft_strtrim(s1, set);
// 	printf("Result: '%s'\n", result);
// }