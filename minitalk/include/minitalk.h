/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:53:38 by davidmalase       #+#    #+#             */
/*   Updated: 2025/01/20 18:03:53 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <signal.h>    // For kill(), sigaction(), ...
# include <stdio.h>     // For print_f
# include <stdlib.h>    // For malloc
# include <sys/types.h> // For pid_t
# include <unistd.h>    // For getpid()

// ft_printf
# include "../ft_printf/ft_printf.h"

// Utils
int		ft_atoi(const char *str);
double	ft_power(double base, int exp);

#endif