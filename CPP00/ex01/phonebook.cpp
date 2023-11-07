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
//	std::cout << "PhoneBook Constructor called" << std::endl;
	return;
}

Phonebook::~Phonebook( void ) {
//	std::cout << "PhoneBook Destructor called" << std::endl;
	return;
}

void Phonebook::addcontact() {
    std:string Fn, Ln, Nk, Ph, Ds;
    std::cout << "↓ Insert First Name ↓" << std::endl;
    std::getline(std::cin, Fn);
    std::cout << "↓ Insert Last Name ↓" << std::endl;
    std::getline(std::cin, Ln);
    std::cout << "↓ Insert Nickname ↓" << std::endl;
    std::getline(std::cin, Nk);
    std::cout << "↓ Insert Phonenumber ↓" << std::endl;
    std::getline(std::cin, Ph);
    std::cout << "↓ Insert Darkest Secret ↓" << std::endl;
    std::getline(std::cin, Ds);
    this->Contacts[this->index++ % max] = Contact(Fn, Ln, Nk, Ph, Ds);
}

void Phonebook::searchlist ( void ) {

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << " INDEX " << "|" << " First Name " << "|" << " Last Name " << "|" << " Nickname " << "|" << std::endl;
	for (int i = 0; i < 9; i++) {
		std::cout << "|   " << std::setw(10) << i << "   |            |           |          |" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	return;
}
