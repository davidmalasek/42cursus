/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:41:12 by dmalasek          #+#    #+#             */
/*   Updated: 2024/10/02 20:30:27 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	process(const char *format, va_list args, int *count)
{
	int				number;
	char			*str;
	int				i;
	int				character;
	unsigned long	pointer_address;
	char			buffer[17];
	unsigned int	unsigned_int;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
				print_sint(args);
			else if (*format == 's')
				print_str(args);
			else if (*format == 'c')
				print_char(args);
			else if (*format == 'p')
				print_ptadd(args);
			else if (*format == 'u')
			{
				// TODO: I ended here
				unsigned_int = va_arg(args, unsigned int);
				ft_putnbr_fd(unsigned_int, 1);
			}
			else if (*format == 'x')
			{
				if (number == 0)
					ft_putchar_fd('0', 1);
				else
				{
					i = 0;
					unsigned_int = va_arg(args, unsigned int);
					while (unsigned_int != 0)
					{
						if (unsigned_int % 16 < 10)
							buffer[i] = '0' + unsigned_int % 16;
						else
							buffer[i] = 'a' + unsigned_int % 16 - 10;
						unsigned_int /= 16;
						i++;
					}
					while (i > 0)
					{
						ft_putchar_fd(buffer[i - 1], 1);
						i--;
					}
				}
			}
			else if (*format == 'X')
			{
				if (number == 0)
					ft_putchar_fd('0', 1);
				else
				{
					i = 0;
					unsigned_int = va_arg(args, unsigned int);
					while (unsigned_int != 0)
					{
						if (unsigned_int % 16 < 10)
							buffer[i] = '0' + unsigned_int % 16;
						else
							buffer[i] = 'A' + unsigned_int % 16 - 10;
						unsigned_int /= 16;
						i++;
					}
					while (i > 0)
					{
						ft_putchar_fd(buffer[i - 1], 1);
						i--;
					}
				}
			}
			else if (*format == '%')
			{
				ft_putchar_fd('%', 1);
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
	return (count);
}

int	main(void)
{
	return (0);
}
