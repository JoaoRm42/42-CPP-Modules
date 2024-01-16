NAME	=	28B
CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -g -std=c++98
SRC		=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
			@rm -rf $(OBJ)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all
