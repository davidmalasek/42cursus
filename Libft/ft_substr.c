/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:09:49 by davidmalase       #+#    #+#             */
/*   Updated: 2024/09/20 13:33:18 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_substr;
	size_t	i;

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
