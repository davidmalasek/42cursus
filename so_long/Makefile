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

# This works for Linux only
$(NAME): minilibx-linux/libmlx.a $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L minilibx-linux -lmlx -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
