# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leo <leo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/02/08 17:44:22 by leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
NAME = libftprintf.a
SRC = *.c	
LIBFT = libft/
SRCS = $(addprefix ./src, $(SRC))
FLAGS = -Wall -Wextra -Werror -I. -I includes
OBJ = $(SRC:.c=.o)

all: #$(NAME)

#  $(NAME): $(OBJ)
#	gcc $(FLAGS) -c $(SRCS)
#	ar rc $(NAME) $(OBJ)
	@make -C $(LIBFT)

clean:
	/bin/rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all