# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 16:14:47 by dmalasek          #+#    #+#              #
#    Updated: 2025/01/21 16:03:27 by dmalasek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Source files
SRC = src/push_swap.c

# Output binaries
NAME = push_swap

# Library paths
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/ft_printf.a

# Object files
OBJ = $(SRC:.c=.o)


# Rules
all: $(NAME)

$(NAME): $(PRINTF_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PRINTF_LIB)

# Build ft_printf
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

