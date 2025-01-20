# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 19:30:39 by dmalasek          #+#    #+#              #
#    Updated: 2025/01/20 13:33:46 by dmalasek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -g -D__linux__
MLX_DIR = minilibx_linux
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# Source files
SRC = file.c main.c map.c utils.c valid.c render.c logic.c valid2.c utils2.c deinit.c
SRC := $(addprefix src/, $(SRC))

# Output
NAME = so_long
OBJ = $(SRC:.c=.o)

# Library paths
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/ft_printf.a

# Rules
all: $(NAME)

$(NAME): $(MLX_DIR)/libmlx.a $(PRINTF_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) $(PRINTF_LIB)

# Build ft_printf
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

# Build minilibx
$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
