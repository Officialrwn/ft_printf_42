# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leo <leo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 12:39:13 by leotran           #+#    #+#              #
#    Updated: 2022/02/15 20:36:54 by leo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/
NAME = libftprintf.a
SRC = 	char_printf.c flags_printf.c int_printf.c length_printf.c \
		pointers_printf.c ft_printf.c tools.c get_formats.c
SRCS = $(addprefix ./src/, $(SRC))
FLAGS = -Wall -Wextra -Werror -I. -I includes
OBJ = *.o

all: $(NAME)
	
$(NAME):
	@make -C $(LIBFT)
	cp $(LIBFT)libft.a $(NAME)
	gcc $(FLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJ)

clean:
	@make -C $(LIBFT) clean
	rm -rf $(OBJ)
	rm -rf $(SURPL_O)

fclean: clean
	@make -C $(LIBFT) fclean
	rm -rf $(NAME)

re: fclean all