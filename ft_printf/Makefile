# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 10:51:13 by edolgun           #+#    #+#              #
#    Updated: 2022/12/04 10:52:52 by edolgun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c

OBJ		= $(SRC:.c=.o)

NAME	= libftprintf.a

CC		= @gcc

CFLAGS	= -Wall -Wextra -Werror -I.

RM		= @rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
			@ar rcs $(NAME) $(OBJ)

clean:	
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)
