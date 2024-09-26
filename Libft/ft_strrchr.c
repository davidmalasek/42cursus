/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:13:50 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/26 11:35:15 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	const char		*last_occurrence = NULL;
	unsigned char	unsigned_char;

	unsigned_char = (unsigned char)character;
	while (*str != '\0')
	{
		if ((unsigned char)*str == unsigned_char)
			last_occurrence = str;
		str++;
	}
	if (unsigned_char == '\0')
		return ((char *)str);
	return ((char *)last_occurrence);
}
