# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 16:14:47 by dmalasek          #+#    #+#              #
#    Updated: 2025/01/21 19:49:44 by davidmalase      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Source files
SRC = src/push_swap.c src/utils.c

# Output
NAME = push_swap

# Library paths
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Object files
OBJ = $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB)

# Build libft
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re


