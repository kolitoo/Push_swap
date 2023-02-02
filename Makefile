# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:55:09 by abourdon          #+#    #+#              #
#    Updated: 2023/02/01 11:10:02 by abourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
LIBFT_PATH = ./libft/
LIBFT = libft/libft.a
RM = rm -rf

SRC =	main.c \
	fonctions/lst.c \
	fonctions/check.c \
	fonctions/instructions.c \
	fonctions/resolve.c \
	fonctions/double_instruction.c \
	fonctions/sort.c \
	fonctions/check_pos.c \
	fonctions/utils.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

clean: $(clean)
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: init all clean fclean re