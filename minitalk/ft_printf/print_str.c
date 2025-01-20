/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:41:08 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/05 12:24:28 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(va_list *args, int *count)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1, count);
}
