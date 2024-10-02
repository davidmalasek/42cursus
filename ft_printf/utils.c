/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:50:04 by dmalasek          #+#    #+#             */
/*   Updated: 2024/10/02 19:39:03 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	char	minus_sign;
	char	string;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	minus_sign = '-';
	if (n < 0)
	{
		write(fd, &minus_sign, 1);
		n = -n;
	}
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	string = (n % 10) + '0';
	write(fd, &string, 1);
}
size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}
