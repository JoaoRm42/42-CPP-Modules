NAME	=	canonical
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -g -std=c++98
SRC		=	main.cpp Fixed.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
			@rm -rf $(OBJ)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all
