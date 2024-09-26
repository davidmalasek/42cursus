/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:54:02 by davidmalase       #+#    #+#             */
/*   Updated: 2024/09/26 11:34:57 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_length;
	char	*final_str;
	int		i;
	int		e;

	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	final_str = malloc((total_length + 1) * sizeof(char));
	if (!final_str)
		return (NULL);
	i = 0;
	e = 0;
	while (s1[i] != '\0')
		final_str[e++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		final_str[e++] = s2[i++];
	final_str[e] = '\0';
	return (final_str);
}
