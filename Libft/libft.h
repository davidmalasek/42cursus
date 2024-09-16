/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:26:53 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/16 16:28:19 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

#define LIBFT_H

#include <string.h>

void	ft_bzero(void *s, size_t n);
int	ft_isalnum(int character);
int	ft_isalpha(int character);
int	ft_isascii(int character);
int	ft_isdigit(int character);
int	ft_isprint(int character);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
int	ft_strlen(char *str);
char	*strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_tolower(char *str);
char	*ft_toupper(char *str);

#endif

// TODO remove includes all over the places
// TODO i end up doing strnstr.c