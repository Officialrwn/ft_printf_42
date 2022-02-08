# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leo <leo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/02/08 10:15:32 by leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
NAME = libftprintf.a
SRC = *.c	

SRCS = $(addprefix ./src, $(SRC))
FLAGS = -Wall -Wextra -Werror -I. -I includes
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all