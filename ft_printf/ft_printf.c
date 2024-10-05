/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:25:00 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/05 12:37:19 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conversion(const char *format, va_list *args, int *count)
{
	if (*format == 'd' || *format == 'i')
		print_sint(args, count);
	else if (*format == 's')
		print_str(args, count);
	else if (*format == 'c')
		print_char(args, count);
	else if (*format == 'p')
		print_ptadd(args, count);
	else if (*format == 'u')
		print_uint(args, count);
	else if (*format == 'x')
		print_lhex(args, count);
	else if (*format == 'X')
		print_uhex(args, count);
	else if (*format == '%')
		ft_putchar_fd('%', 1, count);
	else
		print_invalid(format, count);
}

void	process(const char *format, va_list *args, int *count)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_conversion(format, args, count);
		}
		else
			ft_putchar_fd(*format, 1, count);
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	process(format, &args, &count);
	va_end(args);
	return (count);
}
