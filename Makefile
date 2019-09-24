# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 15:08:31 by rhoorntj          #+#    #+#              #
#    Updated: 2019/07/23 18:39:50 by rhoorntj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = read.c tetro.c libft/li


INCLUDE = read.h

all : $(NAME)

$(NAME):
	@gcc -c $(SRC) libft/libft.a

clean:
	@/bin/rm -f *.o *.gch

fclean:	clean
	@/bin/rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re
