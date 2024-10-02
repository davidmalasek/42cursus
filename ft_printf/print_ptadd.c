/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:26:28 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/02 20:27:50 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	print_ptadd(va_list args)
{
	int				i;
	unsigned long	pointer_address;
	char			buffer[17];

	i = 0;
	pointer_address = (unsigned long)va_arg(args, void *);
	if (pointer_address == 0)
		ft_putstr_fd("0x0", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		while (pointer_address != 0)
		{
			if (pointer_address % 16 < 10)
				buffer[i] = '0' + pointer_address % 16;
			else
				buffer[i] = 'a' + pointer_address % 16 - 10;
			pointer_address /= 16;
			i++;
		}
		while (i > 0)
		{
			ft_putchar_fd(buffer[i - 1], 1);
			i--;
		}
	}
}
