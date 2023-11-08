/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:37 by joaoped2          #+#    #+#             */
/*   Updated: 2023/11/08 19:13:35 by marvin           ###   ########.fr       */
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
    system("clear");
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
    this->Contacts[this->index++ % max].setValues(Fn, Ln, Nk, Ph, Ds);
    system("clear");
    std::cout << "Contact Added Successfully" << std::endl;
    usleep(2000000);
    system("clear");
    return;
}

int Phonebook::GetIntLength(int number) {
    if (number == 0) {
        return 1;
    }

    int length = 0;
    while (number != 0) {
        number /= 10;
        length++;
    }
    return length;
}

int Phonebook::finalresult( std::string checker ) {
    if (checker.empty())
    {
        system("clear");
        std::cout << "Contact is empty" << std::endl;
        usleep(2000000);
        system("clear");
        SearchList();
    }
    else
        return (1);
    return(0);
}

int Phonebook::checklist ( int index, std::string intput_str, std::string checker) {
    if (std::cin.eof())
        return (2);
    else if (GetIntLength(index) > 1 || !isdigit(intput_str.front()))
    {
        system("clear");
        std::cout << "That's not a valid number!" << std::endl;
        usleep(2000000);
        system("clear");
        return SearchList();
    }
    else if (index < 0 || index >= this->index)
    {
        system("clear");
        std::cout << "That number is not a valid index" << std::endl;
        usleep(2000000);
        system("clear");
        return SearchList();
    }
    else
        return finalresult(checker);
}

int Phonebook::SearchList( void ) {
    const char *cpy;
    std::string intput_str;
    std::string checker;
    int val;
    int index;
    
    system("clear");
    if (this->index == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
        usleep(2000000);
        system("clear");
        return (0);
    }
    DisplayContact();
    std::cout << "→ ";
    std::cin >> intput_str;
    if (intput_str == "EXIT")
        return (0);
    cpy = intput_str.c_str();
    index = atoi(cpy);
    checker = this->Contacts[index].SetString(this->Contacts[index].GetFirst());
    val = checklist(index, intput_str, checker);
    if (val == 1)
    {
        this->Contacts[index].ShowContact();
        system("clear");
    }
    else if (val == 2)
        return (2);
    return (0);
}

void DisplayMenu ( void ) {
    std::cout << "+———————————————————————————————————————————————————————+" <<std::endl;
    std::cout << "| Type the index number of the contact you want to view |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "| Type EXIT to go back to the Main menu                 |" <<std::endl;
    std::cout << "+———————————————————————————————————————————————————————+\n" <<std::endl;
}

void Phonebook::DisplayContact ( void ) {
    std::string str;

    DisplayMenu();
    std::cout << "+———————————————————————————————————————————+" << std::endl;
    std::cout << "|  Index   |First Name|Last Name |  Nickname|" << std::endl;
    for (int i = 0; i < max; i++)
    {
        std::cout << "|——————————|——————————|——————————|——————————|" << std::endl;
        std::cout << "|" << std::setw(10) << i << "|";
        str = this->Contacts[i].SetString(this->Contacts[i].GetFirst());
        std::cout << std::setw(10) << str << "|";
        str = this->Contacts[i].SetString(this->Contacts[i].GetLast());
        std::cout << std::setw(10) << str << "|";
        str = this->Contacts[i].SetString(this->Contacts[i].GetNick());
        std::cout << std::setw(10) << str << "|" << std::endl;
    }
    std::cout << "+——————————+——————————+——————————+——————————+" << std::endl;
	return ;
}
