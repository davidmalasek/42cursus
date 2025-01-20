# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 16:14:47 by dmalasek          #+#    #+#              #
#    Updated: 2025/01/20 17:09:27 by dmalasek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Source files
CLIENT_SRC = src/client.c
SERVER_SRC = src/server.c
UTILS_SRC = src/utils.c

# Output binaries
SERVER_NAME = server
CLIENT_NAME = client

# Library paths
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/ft_printf.a

# Object files
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

# Rules
all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(PRINTF_LIB) $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJ) $(UTILS_OBJ) $(PRINTF_LIB)

$(CLIENT_NAME): $(PRINTF_LIB) $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJ) $(UTILS_OBJ) $(PRINTF_LIB)

# Build ft_printf
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(UTILS_OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

