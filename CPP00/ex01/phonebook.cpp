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
    this->index = 0;
    this->max = 8;
	return;
}

Phonebook::~Phonebook( void ) {
//	std::cout << "PhoneBook Destructor called" << std::endl;
	return;
}

void Phonebook::AddContact( void ) {
    std::string Fn, Ln, Nk, Ph, Ds;
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
//    this->Contacts[this->index].setValues(Fn, Ln, Nk, Ph, Ds);
    this->Contacts[this->index++ % max].setValues(Fn, Ln, Nk, Ph, Ds);
}

void Phonebook::SearchList ( void ) {
    std::string str;

    std::cout << "|  Index   |First Name|Last Name |  Nickname|" << std::endl;
    for (int i = 0; i < max; i++)
    {
        std::cout << "|" << std::setw(10) << i << "|";
        str = this->Contacts[i].SetString(this->Contacts[i].GetFirst());
        std::cout << std::setw(10) << str << "|";
        str = this->Contacts[i].SetString(this->Contacts[i].GetLast());
        std::cout << std::setw(10) << str << "|";
        str = this->Contacts[i].SetString(this->Contacts[i].GetNick());
        std::cout << std::setw(10) << str << "|" << std::endl;
    }
    std::cout << "--------------------------------------------------------------------" << std::endl;
	return;
}
