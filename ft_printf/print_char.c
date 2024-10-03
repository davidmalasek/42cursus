/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:23:55 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/03 10:53:06 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list args, int *count)
{
	int	character;

	character = va_arg(args, int);
	ft_putchar_fd(character, 1, count);
}
