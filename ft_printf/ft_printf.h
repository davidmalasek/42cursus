/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:49:33 by dmalasek          #+#    #+#             */
/*   Updated: 2024/10/03 10:51:40 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdarg.h>
# include <stdio.h> // TODO delete this one
# include <unistd.h>

/*Main*/
void	process(const char *format, va_list args, int *count);
int		ft_printf(const char *format, ...);

/*Utils*/
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd, int *count);

/*Printing functions*/
void	print_sint(va_list args, int *count);
void	print_str(va_list args, int *count);
void	print_char(va_list args, int *count);
void	print_ptadd(va_list args, int *count);
void	print_uint(va_list args, int *count);
void	print_lhex(va_list args, int *count);
void	print_uhex(va_list args, int *count);
void	print_invalid(const char *format, int *count);

#endif