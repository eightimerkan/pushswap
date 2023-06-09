# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 05:25:05 by edolgun           #+#    #+#              #
#    Updated: 2022/12/04 10:52:56 by edolgun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap_utils.c sort_the_list.c smaller_list.c indexing.c check.c \
		push_swap_utils_2.c sort_the_list2.c errors.c read_numbers.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(SRC) ./ft_printf/libftprintf.a main.c -o $(NAME)

all: $(NAME)

bonus: $(OBJ)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(SRC) ./ft_printf/libftprintf.a ./gnl/get_next_line.c ./gnl/get_next_line_utils.c checker.c -o checker

clean:
	rm -rf $(OBJ)
	rm -rf checker
	rm -rf main.o
	make -C ./ft_printf clean

fclean: clean
	rm -rf $(OBJ) $(NAME)
	make -C ./ft_printf fclean

re: fclean all

.PHONY: all re clean fclean 