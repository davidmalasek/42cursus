/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:28:03 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/24 17:38:16 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO: doesnt work

int	is_separator(char character, char *charset)
{
	while (*charset)
	{
		if (*charset == character)
			return (1);
		charset++;
	}
	return (0);
}

int	calculate_array_length(char *str, char *charset)
{
	int	i;
	int	non_sep_string_count;

	i = 0;
	non_sep_string_count = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], charset))
			i++;
		else
		{
			non_sep_string_count++;
			while (!is_separator(str[i], charset) && str[i] != '\0')
				i++;
		}
	}
	return (non_sep_string_count);
}

char	*get_substring(char *str, int start_index, int end_index)
{
	int		i;
	char	*return_str;

	i = 0;
	return_str = malloc(end_index - start_index + 1);
	while (start_index < end_index)
	{
		return_str[i] = str[start_index];
		start_index++;
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}

void	add_to_array(char *str, int *start_index, int end_index,
		char **array_pos)
{
	*array_pos = get_substring(str, *start_index, end_index);
	*start_index = end_index;
}

char	**ft_split(char *str, char *charset)
{
	int		x;
	int		y;
	int		z;
	char	**array;

	x = 0;
	y = 0;
	z = 0;
	array = malloc((calculate_array_length(str, charset) + 1) * sizeof(char *));
	while (str[x] != '\0')
	{
		if (is_separator(str[x], charset))
		{
			x++;
			y++;
		}
		else
		{
			while (!is_separator(str[x], charset) && str[x] != '\0')
				x++;
			add_to_array(str, &y, x, &array[z++]);
		}
	}
	array[z] = NULL;
	return (array);
}
