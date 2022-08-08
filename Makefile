# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 16:38:44 by ebresser          #+#    #+#              #
#    Updated: 2022/08/08 01:00:22 by jaqrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_DIR = src
OBJ_DIR = .obj

SRC =	$(SRC_DIR)/actions.c \
		$(SRC_DIR)/create_forks.c \
		$(SRC_DIR)/create_philos.c \
		$(SRC_DIR)/create_threads.c \
		$(SRC_DIR)/errors.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/routines.c \
		$(SRC_DIR)/set_input.c \
		$(SRC_DIR)/time.c \
		$(SRC_DIR)/utils_number.c \
		$(SRC_DIR)/ft_putstr.c \
		$(SRC_DIR)/utils_str.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = clang
HEAD = -I./includes
CFLAGS = -Wall -Werror -Wextra -g
LFLAGS = -pthread
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $(<F)"

clean:
		@$(RM) $(OBJ_DIR)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"

fclean: clean
		@$(RM) $(NAME)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving philo\033[0m"

re: fclean all

.PONY: all clean fclean re