/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:33:23 by dmalasek          #+#    #+#             */
/*   Updated: 2024/10/05 12:28:58 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uint(va_list *args, int *count)
{
	unsigned int	unsigned_int;

	unsigned_int = va_arg(*args, unsigned int);
	ft_putunbr_fd(unsigned_int, 1, count);
}
