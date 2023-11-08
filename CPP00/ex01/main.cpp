/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:03:22 by joaoped2          #+#    #+#             */
/*   Updated: 2023/11/08 18:30:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <unistd.h>

void	menu( void ) {
	std::cout << "+———————————————————————————————————————+" << std::endl;
	std::cout << "| ADD    → Add contact to the Phonebook |" << std::endl;
	std::cout << "| SEARCH → Search for a contact         |" << std::endl;
	std::cout << "| EXIT   → Exit the program             |" << std::endl;
	std::cout << "+———————————————————————————————————————+" << std::endl;
	std::cout << "→ ";
}

int	main()
{
	Phonebook	pb;
	std::string	Input;
	int error;

	std::cout << "\033[2J\033[H";
	while (1) {
		menu();
		std::getline(std::cin, Input);
		if (Input == "ADD")
            pb.AddContact();
		else if (Input == "SEARCH")
		{
			error = pb.SearchList();
			if (error == 2)
				break ;
		}	
		else if (Input == "EXIT")
			break ;
		else
		{
			if (std::cin.eof())
				break ;
			system("clear");
		}
	}
	return (0);
}
