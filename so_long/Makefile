# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 14:19:12 by davidmalase       #+#    #+#              #
#    Updated: 2025/01/16 15:22:45 by davidmalase      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK_OS = $(shell uname -s)

ifeq ($(CHECK_OS), Darwin)
	CC = clang
	CFLAGS = -Wall -Werror -Wextra -Iinclude -g -D__APPLE__ -DGL_SILENCE_DEPRECATION
	MLX_DIR = minilibx_macos
	FRAMEWORKS = -framework OpenGL -framework AppKit
	LIBS = -L$(MLX_DIR) -lmlx $(FRAMEWORKS)
else
	CC = cc
	CFLAGS = -Wall -Werror -Wextra -Iinclude -g -D__linux__
	MLX_DIR = minilibx_linux
	LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

# Source files
SRC = file.c main.c map.c utils.c valid.c render.c logic.c valid2.c utils2.c deinit.c
SRC := $(addprefix src/, $(SRC))

# Output
NAME = so_long
OBJ = $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(MLX_DIR)/libmlx.a $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) ft_printf/ft_printf.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
