/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:41:08 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/02 20:23:10 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	print_str(va_list args)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(args, char *);
	ft_putstr_fd(str, 1);
}
