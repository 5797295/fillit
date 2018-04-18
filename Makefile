#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 13:54:38 by mkass             #+#    #+#              #
#    Updated: 2018/03/26 18:23:03 by mkass            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

FILES = fillit.c handling.c check_square.c check_char.c check_char_number.c check_shape.c solve.c board.c fill_in.c store.c main.c
SRC = $(addprefix src/, $(FILES))
CFLAGS = -I. -Wall -Wextra -Werror
LFLAGS = -L ./libft/ -lft
OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): lib
	@gcc $(CFLAGS) -c $(SRC)
	@gcc $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f *.o *~ */*.o */*~

fclean: clean
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all

lib:
	@make -C ./libft
	@make clean -C ./libft
