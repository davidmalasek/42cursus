/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:33:23 by dmalasek          #+#    #+#             */
/*   Updated: 2024/10/03 10:53:06 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uint(va_list args, int *count)
{
	unsigned int	unsigned_int;

	unsigned_int = va_arg(args, unsigned int);
	ft_putnbr_fd(unsigned_int, 1, count);
}
