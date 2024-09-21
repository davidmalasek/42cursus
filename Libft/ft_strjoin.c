/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:54:02 by davidmalase       #+#    #+#             */
/*   Updated: 2024/09/21 12:56:01 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[e] != '\0')
	{
		dest[i] = src[e];
		i++;
		e++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_total_length(int size, char **strs, char *sep)
{
	int	i;
	int	total_length;

	i = 0;
	total_length = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	return (total_length + (size - 1) * ft_strlen(sep) + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int total_length;
	char *final_str;

	i = 0;
	total_length = get_total_length(size, strs, sep);
	if (size == 0)
	{
		final_str = malloc(1);
		final_str[0] = '\0';
		return (final_str);
	}
	final_str = malloc(total_length * sizeof(char));
	if (!final_str)
		return (0);
	final_str[0] = '\0';
	while (i < size)
	{
		ft_strcat(final_str, strs[i]);
		if (i + 1 < size)
			ft_strcat(final_str, sep);
		i++;
	}
	return (final_str);
}