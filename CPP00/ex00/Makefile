NAME	=	megaphone
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -g -std=c++98
SRC		=	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $@ $^

%.o:		%.c
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@rm -rf $(OBJ)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all
