# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 17:46:55 by rhoorntj          #+#    #+#              #
#    Updated: 2019/10/23 12:10:55 by rhoorntj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): makelibft
	gcc -g -c $(FLAGS) *.c -I libft/
	gcc *.o libft/libft.a -o $(NAME)

makelibft:
	make -C libft

clean:
	/bin/rm -f *.o
	/bin/rm -f libft/*.o

fclean: clean
	/bin/rm -f $(NAME) libft.a
	/bin/rm -f libft/libft.a

re: fclean all

.PHONY : all clean fclean re makelibft
