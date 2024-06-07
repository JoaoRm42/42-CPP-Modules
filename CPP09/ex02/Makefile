# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:27:17 by joaoped2          #+#    #+#              #
#    Updated: 2024/06/06 10:10:39 by joaoped2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = PmergeMe
CXX  	 = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g
SRC      = main.cpp PmergeMe.cpp
OBJ		 = $(SRC:%.cpp=%.o)

%.o:	%.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling ..."
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "Compilation Successful"

clean:
	@rm -rf $(OBJ)
	@echo "\033[31mObject files removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mObject files and btc removed\033[0m"

re: fclean all