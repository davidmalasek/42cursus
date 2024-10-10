/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:44 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/10 17:58:29 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *string, int character)
{
	unsigned char	unsigned_char;

	unsigned_char = (unsigned char)character;
	while (*string)
	{
		if ((unsigned char)*string == unsigned_char)
			return ((char *)string);
		string++;
	}
	if (unsigned_char == '\0')
		return ((char *)string);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	int		length;
	int		i;
	char	*new_str;

	length = 0;
	while (src[length])
		length++;
	new_str = malloc(length + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_length;
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
