/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:35:42 by dmalasek          #+#    #+#             */
/*   Updated: 2024/10/03 11:34:34 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_lhex(va_list args, int *count)
{
	int				i;
	unsigned int	unsigned_int;
	char			buffer[8];

	i = 0;
	unsigned_int = va_arg(args, unsigned int);
	if (unsigned_int == 0)
	{
		ft_putchar_fd('0', 1, count);
		return ;
	}
	while (unsigned_int != 0)
	{
		if (unsigned_int % 16 < 10)
			buffer[i] = '0' + unsigned_int % 16;
		else
			buffer[i] = 'a' + unsigned_int % 16 - 10;
		unsigned_int /= 16;
		i++;
	}
	while (i > 0)
	{
		ft_putchar_fd(buffer[i - 1], 1, count);
		i--;
	}
}
