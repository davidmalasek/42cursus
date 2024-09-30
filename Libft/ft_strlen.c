/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:09:01 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/30 16:27:02 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlen
** Calculates the length of a string
*/

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
