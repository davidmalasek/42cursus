/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:28:03 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/26 11:34:41 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *str, char c)
{
	int	count;
	int	i;
	int	is_in_word;

	count = 0;
	i = 0;
	is_in_word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && is_in_word == 0)
		{
			is_in_word = 1;
			count++;
		}
		else if (str[i] == c)
			is_in_word = 0;
		i++;
	}
	return (count);
}

char	*extract_word(const char *str, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	result = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result[j++] = extract_word(&s[i], c);
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}
