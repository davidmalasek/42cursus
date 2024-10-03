/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:41:08 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/03 10:53:06 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(va_list args, int *count)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(args, char *);
	ft_putstr_fd(str, 1, count);
}
