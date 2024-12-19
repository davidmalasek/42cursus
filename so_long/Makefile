# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = file.c main.c map.c utils.c valid.c
SRC := $(addprefix src/, $(SRC))

# MiniLibX
MLX_DIR = minilibx_macos

# Output
NAME = so_long
OBJ = $(SRC:.c=.o)

# Rules
all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $^ -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re