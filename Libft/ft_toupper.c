/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:37:40 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/21 12:32:38 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_toupper(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((int)str[index] < 123 && (int)str[index] > 96
			&& (int)str[index] != 32)
		{
			str[index] = str[index] - 32;
		}
		index++;
	}
	return (str);
}
