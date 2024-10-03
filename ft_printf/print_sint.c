/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:38:18 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/03 10:53:06 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sint(va_list args, int *count)
{
	int	number;

	number = va_arg(args, int);
	ft_putnbr_fd(number, 1, count);
}
