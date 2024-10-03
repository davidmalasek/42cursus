# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = ft_printf.c print_char.c print_invalid.c print_lhex.c print_ptadd.c print_sint.c print_str.c print_uhex.c print_uint.c utils.c

# Output
NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
AR = ar crs

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re