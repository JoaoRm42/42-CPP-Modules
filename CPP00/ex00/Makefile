# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 16:58:41 by joaoped2          #+#    #+#              #
#    Updated: 2023/10/27 16:58:43 by joaoped2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -g -std=c++98
SRC		=	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
			@rm -rf $(OBJ)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all
