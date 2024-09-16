/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:40:59 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/16 12:46:06 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int character)
{
	if ((character >= 0 && character <= 127))
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int character = 200;

// 	printf("My result: %d\n", ft_isascii(character));
// 	printf("isascii() result: %d\n", isascii(character));
// }