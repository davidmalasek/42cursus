/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:15:29 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/18 22:05:16 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	e;
	char	first_char;
	char	first_occ;

	i = 0;
	e = 0;
	if (*little == '\0')
		return (big);
	first_char = *little;
	while (i != len && big[i] != '\0')
	{
		little = first_char;
		while (little[e] != '\0')
		{
			if (big[i] == little[0])
			{
				while (big[i] == little[e])
				{
				}
			}
		}
		big++;
		i++;
	}
}

int	main(void)
{
}