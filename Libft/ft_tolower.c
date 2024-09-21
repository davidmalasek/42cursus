/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:38:32 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/21 12:32:34 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tolower(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((int)str[index] > 64 && (int)str[index] < 91
			&& (int)str[index] != 32)
		{
			str[index] = str[index] + 32;
		}
		index++;
	}
	return (str);
}
