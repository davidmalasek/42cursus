/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:23:55 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/02 20:25:44 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	print_char(va_list args)
{
	int	character;

	character = va_arg(args, int);
	ft_putchar_fd(character, 1);
}
