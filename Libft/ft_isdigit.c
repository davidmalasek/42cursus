/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:21:38 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/16 12:39:34 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int character)
{
	if ((character >= 48 && character <= 57))
		return (2048);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int character = '-';

// 	printf("My result: %d\n", ft_isdigit(character));
// 	printf("isdigit() result: %d\n", isdigit(character));
// }