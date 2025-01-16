/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:26:28 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/07 15:03:45 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_mem_address(unsigned long pointer_address, int *count)
{
	int		i;
	char	buffer[17];

	ft_putstr_fd("0x", 1, count);
	i = 0;
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
		ft_putchar_fd(buffer[i - 1], 1, count);
		i--;
	}
}

void	print_ptadd(va_list *args, int *count)
{
	unsigned long	pointer_address;

	pointer_address = (unsigned long)va_arg(*args, void *);
	if (pointer_address == 0)
	{
		ft_putstr_fd("(nil)", 1, count);
		return ;
	}
	else
		create_mem_address(pointer_address, count);
}
