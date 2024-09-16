/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:38:32 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/16 14:39:17 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
