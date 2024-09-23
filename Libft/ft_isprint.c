/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:21:38 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/23 18:18:50 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int character)
{
	if (character >= 32 && character <= 126)
		return (16384);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int character = '\n';

// 	printf("My result: %d\n", ft_isprint(character));
// 	printf("isprint() result: %d\n", isprint(character));
// }