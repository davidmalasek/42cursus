# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = file.c main.c map.c utils.c valid.c
SRC := $(addprefix src/, $(SRC))

# Output
NAME = so_long
OBJ = $(SRC:.c=.o)

# Rules
all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $^ -o $@

# TODO: This works for Mac OS - change for Linux accordingly
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -L mlx42/build -lmlx42 -L /opt/homebrew/Cellar/glfw/3.4/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re