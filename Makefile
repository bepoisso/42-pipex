# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 14:07:44 by bepoisso          #+#    #+#              #
#    Updated: 2025/01/23 16:46:55 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_________________VARIABLE_________________

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR)
ARGS = i "cat -e" "cat -e" o
VALARGS = --track-fds=yes --leak-check=full --track-origins=yes --show-leak-kinds=all --trace-children=yes

#_________________FILES_________________

SRC_DIR = ./srcs
OBJ_DIR = ./objs
INC_DIR = ./includes

SRC_FILES = \
	pipex.c \
	pipes.c \
	utiles.c \
	args.c\
	redirect.c\

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

#_________________RULES_________________

all: $(NAME)

$(NAME): $(OBJS)
	@make all -C libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make clean -C libft
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

val:
	valgrind $(VALARGS) ./$(NAME) $(ARGS)

exec:
	./$(NAME) $(ARGS)

debug:
	gdb -tui -q ./$(NAME)

.PHONY: all clean fclean re
