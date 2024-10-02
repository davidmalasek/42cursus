/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:49:33 by dmalasek          #+#    #+#             */
/*   Updated: 2024/10/02 20:29:49 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdarg.h>
# include <stdio.h> // TODO delete this one
# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	print_sint(va_list args);
void	print_str(va_list args);
void	print_char(va_list args);
void	print_ptadd(va_list args);

#endif