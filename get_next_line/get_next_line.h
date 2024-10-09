/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:47:57 by davidmalase       #+#    #+#             */
/*   Updated: 2024/10/09 14:15:30 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024

# include <stdio.h> // TODO: delete this one
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*extract_line(char *buffer, int end);
char	*find_newline(char *buffer);

#endif
