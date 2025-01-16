/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:38:18 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/05 12:11:11 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sint(va_list *args, int *count)
{
	int	number;

	number = va_arg(*args, int);
	ft_putnbr_fd(number, 1, count);
}
