/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:21:38 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/16 12:39:30 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int character)
{
	if ((character >= 65 && character <= 90) || (character >= 97
			&& character <= 122))
		return (1024);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int character = '.';

// 	printf("My result: %d\n", ft_isalpha(character));
// 	printf("isalpha() result: %d\n", isalpha(character));
// }