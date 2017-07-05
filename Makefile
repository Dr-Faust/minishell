# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opodolia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 16:00:27 by opodolia          #+#    #+#              #
#    Updated: 2017/07/05 15:06:18 by opodolia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
NAME_BASE = minishell

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# directories
SH_SRC_DIR = ./src/
SH_OBJ_DIR = ./obj/
SH_INC_DIR = ./includes/

# minishell source files
SH_FILES = main.c env_info.c prompt.c read_line.c split_line.c execute.c \
		   env_to_arr.c access.c ft_echo.c ft_cd.c ft_setenv.c ft_unsetenv.c \
		   ft_help.c parse_dollar.c split_commands.c errors.c

SH_OBJ = $(addprefix $(SH_OBJ_DIR), $(SH_FILES:.c=.o))

# libftprintf
LIB_DIR = ./libft_printf/
LIB = $(addprefix $(LIB_DIR), libftprintf.a)
LIB_INC = -I ./libft_printf
LIB_LNK = -L ./libft_printf -l ftprintf

.SILENT:

all: $(LIB) $(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAME_BASE) is done\033[0m\033[K"

$(SH_OBJ_DIR)%.o: $(SH_SRC_DIR)%.c
	printf "\r\033[38;5;11m⌛  MAKE $(NAME_BASE) please wait ...\033[0m\033[K"
	mkdir -p $(SH_OBJ_DIR)
	$(CC) $(CFLAGS) $(LIB_INC) -I $(SH_INC_DIR) -o $@ -c $<

$(LIB):
	make -C $(LIB_DIR)

$(NAME): $(SH_OBJ)
	$(CC) $(SH_OBJ) $(LIB_LNK) -lm -o $(NAME)
	echo -en "\r\033[38;5;22m☑️  MAKE $(NAME_BASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat author | sed s/^/\ \ \ \ /g`\033[0m\033[K 🇺🇦"

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAME_BASE) please wait ...\033[0m\033[K"
	rm -rf $(SH_OBJ_DIR)
	make -C $(LIB_DIR) clean
	printf "\r\033[38;5;11m☑️  CLEAN  $(NAME_BASE) is done\033[0m\033[K"

fclean: clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAME_BASE) please wait ...\033[0m\033[K"
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean
	printf "\r\033[38;5;11m☑️  FCLEAN  $(NAME_BASE) is done\033[0m\033[K"

re: fclean all

.PHONY: fclean clean re
