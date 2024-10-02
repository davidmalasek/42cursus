/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:38:18 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/02 20:29:45 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	print_sint(va_list args)
{
	int	number;

	number = va_arg(args, int);
	ft_putnbr_fd(number, 1);
}
