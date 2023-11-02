/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:37 by joaoped2          #+#    #+#             */
/*   Updated: 2023/11/02 15:46:43 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook( void ) {

	std::cout << "PhoneBook Constructor called" << std::endl;
	return;
}

Phonebook::~Phonebook( void ) {

	std::cout << "PhoneBook Destructor called" << std::endl;
	return;
}

void Phonebook::searchlist ( void ) {

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << " INDEX " << "|" << " First Name " << "|" << " Last Name " << "|" << " Nickname " << "|" << std::endl;
	for (int i = 0; i < 9; i++) {
		std::cout << "|   " << i << "   |            |           |          |" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	return;
}
