# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 16:14:47 by dmalasek          #+#    #+#              #
#    Updated: 2025/01/26 14:53:14 by davidmalase      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Source files
SRC = src/push_swap.c src/utils/utils.c src/stack/stack.c src/stack/stack_utils.c \
	  src/validation/validation.c src/operations/push_operations.c src/operations/rotate_operations.c \
	  src/operations/reverse_rotate_operations.c src/operations/swap_operations.c \
	  src/sort/sort.c src/helper/helper.c

# Output
NAME = push_swap

# Library paths
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Temporary directory for object files
OBJ_DIR = build
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB)

# Only rebuild libft when necessary
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile .c files into .o files inside the temporary directory
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the build directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re