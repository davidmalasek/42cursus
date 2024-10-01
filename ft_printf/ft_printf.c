/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:41:12 by dmalasek          #+#    #+#             */
/*   Updated: 2024/10/01 13:54:30 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/config.h"

void	process(const char *format, va_list args, int *count)
{
	int		number;
	char	*str;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				number = va_arg(args, int);
				printf("%d\n", number);
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				printf("%s", str);
			}
		}
		else
		{
			ft_putchar_fd(*format, 1);
		}
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	process(format, args, &count);
	va_end(args);
	return (0);
}

int	main(void)
{
	int		first;
	int		second;
	char	string[] = "ahoj";
	char	string2[] = "cus";

	first = 1;
	second = 2;
	ft_printf("ahoj %s %s", string, string2);
}
