/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:21:38 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/16 12:39:42 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int character)
{
	if ((character >= 65 && character <= 90) || (character >= 97
			&& character <= 122) || (character >= 48 && character <= 57))
		return (8);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int character = '8';

// 	printf("My result: %d\n", ft_isalnum(character));
// 	printf("isalnum() result: %d\n", isalnum(character));
// }