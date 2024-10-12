/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:44 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/12 17:15:14 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	size_t			length;
	size_t			i;

	length = count * size;
	i = 0;
	if (!count || !size)
		return (malloc(0));
	if (length / size != count)
		return (NULL);
	result = (unsigned char *)malloc(length);
	if (result == NULL)
		return (NULL);
	while (i < length)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > s_len - start)
		len = s_len - start;
	new_substr = (char *)malloc(len + 1);
	if (!new_substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_substr[i] = s[start + i];
		i++;
	}
	new_substr[i] = '\0';
	return (new_substr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
