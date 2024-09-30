/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:41:12 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/30 18:17:55 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/config.h"

void	process(char *format, va_list args, int *count)
{
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;

	va_start(ptr, *format);
	printf("ahoj");
	return (0);
}

int	main(void)
{
	ft_printf("ahoj %");
}
