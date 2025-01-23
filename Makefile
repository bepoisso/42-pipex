# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 14:07:44 by bepoisso          #+#    #+#              #
#    Updated: 2025/01/23 17:52:04 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_________________COLORS_________________

PURPLE = \033[0;35m
YELLOW = \033[0;93m
RESET = \033[0m

#_________________VARIABLE_________________

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR)
ARGS = infile "cat -e" "rev" outfile
VALARGS = --track-fds=yes --leak-check=full --track-origins=yes --show-leak-kinds=all --trace-children=yes
MAKEFLAGS += --no-print-directory

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
	@echo "Create Libft		✅"
	@$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo "Create Program		✅"
	@echo "$(YELLOW)   _____ ________           __________.__                       $(RESET)"
	@echo "$(YELLOW)  /  |  |\_____  \          \______   \__|_____   _______  ___  $(RESET)"
	@echo "$(YELLOW) /   |  |_/  ____/    ______ |     ___/  \____ \_/ __ \\  \/  / $(RESET)"
	@echo "$(YELLOW)/    ^   /       \   /_____/ |    |   |  |  |_> >  ___/ >    <  $(RESET)"
	@echo "$(YELLOW)\____   |\_______ \          |____|   |__|   __/ \___  >__/\_ \ $(RESET)"
	@echo "$(YELLOW)     |__|        \/                      |__|        \/      \/ $(RESET)"
	@echo "$(PURPLE)                                                By bepoisso 🐟  $(RESET)"
	@echo "$(PURPLE)🤖 To execute : ./pipex infile cmd1 cmd2 outfile 🤖$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make clean -C libft
	@echo "Clean libft Objs	✅"
	@rm -rf $(OBJ_DIR)
	@echo "Clean Program Objs	✅"

fclean: clean
	@make fclean -C libft
	@echo "Clean Libft		✅"
	@rm -f $(NAME)
	@echo "Clean Program		✅"

re: fclean all

val:
	valgrind $(VALARGS) ./$(NAME) $(ARGS)

exec:
	./$(NAME) $(ARGS)

debug:
	gdb -tui -q ./$(NAME)

.PHONY: all clean fclean re
