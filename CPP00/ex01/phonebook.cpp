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

int Phonebook::AddContact( void ) {
    system("clear");
    std::string Fn, Ln, Nk, Ph, Ds;
    std::cout << "+—————————————————————————————————————————+" << std::endl;
    std::cout << "|          ↓ Insert First Name ↓          |" << std::endl;
    std::cout << "+—————————————————————————————————————————+" << std::endl;
    std::cout << "→ ";
    std::getline(std::cin, Fn);
    system("clear");
    if (std::cin.eof())
        return (2);
    std::cout << "+————————————————————————————————————————+" << std::endl;
    std::cout << "|          ↓ Insert Last Name ↓          |" << std::endl;
    std::cout << "+————————————————————————————————————————+" << std::endl;
    std::cout << "→ ";
    std::getline(std::cin, Ln);
    system("clear");
    if (std::cin.eof())
        return (2);
    std::cout << "+———————————————————————————————————————+" << std::endl;
    std::cout << "|          ↓ Insert Nickname ↓          |" << std::endl;
    std::cout << "+———————————————————————————————————————+" << std::endl;
    std::cout << "→ ";
    std::getline(std::cin, Nk);
    system("clear");
    if (std::cin.eof())
        return (2);
    std::cout << "+————————————————————————————————————————+" << std::endl;
    std::cout << "|         ↓ Insert Phonenumber ↓         |" << std::endl;
    std::cout << "+————————————————————————————————————————+" << std::endl;
    std::cout << "→ ";
    std::getline(std::cin, Ph);
    system("clear");
    if (std::cin.eof())
        return (2);
    std::cout << "+———————————————————————————————————————+" << std::endl;
    std::cout << "|       ↓ Insert Darkest Secret ↓       |" << std::endl;
    std::cout << "+———————————————————————————————————————+" << std::endl;
    std::cout << "→ ";
    std::getline(std::cin, Ds);
    system("clear");
    if (std::cin.eof())
        return (2);
    this->Contacts[this->index++ % max].setValues(Fn, Ln, Nk, Ph, Ds);
    system("clear");
    std::cout << "+——————————————————————————————————————+" << std::endl;
    std::cout << "|      Contact Added Successfully      |" << std::endl;
    std::cout << "+——————————————————————————————————————+" << std::endl;
    usleep(2000000);
    system("clear");
    return(0);
}

int Phonebook::FinalResult( int index ) {
    std::string checker;
    checker = this->Contacts[index].SetString(this->Contacts[index].GetFirst());
    if (checker.empty())
    {
        system("clear");
        std::cout << "+——————————————————————————————————————+" << std::endl;
        std::cout << "|           Contact is empty           |" << std::endl;
        std::cout << "+——————————————————————————————————————+" << std::endl;
        usleep(2000000);
        system("clear");
    }
    else
        return (1);
    return(0);
}

int Phonebook::checklist ( int index, std::string intput_str ) {
    if (std::cin.eof())
        return (2);
    else if (intput_str.length() > 1 || !isdigit(intput_str.front()))
    {
        system("clear");
        std::cout << "+——————————————————————————————————————+" << std::endl;
        std::cout << "|      That's not a valid number!      |" << std::endl;
        std::cout << "+——————————————————————————————————————+" << std::endl;
        usleep(2000000);
        system("clear");
    }
    else if (index < 0 || index > this->max - 1)
    {

        system("clear");
        std::cout << "+————————————————————————————————————————+" << std::endl;
        std::cout << "|    That number is not a valid index    |" << std::endl;
        std::cout << "+————————————————————————————————————————+" << std::endl;
        usleep(2000000);
        system("clear");
    }
    else
        return FinalResult( index );
    return (0);
}

int Phonebook::SearchList( void ) {
    const char *cpy;
    std::string intput_str;
    int val = 0;
    int index;
    
    system("clear");
    if (this->index == 0)
    {
        std::cout << "+——————————————————————————————————————+" << std::endl;
        std::cout << "|          PhoneBook is empty          |" << std::endl;
        std::cout << "+——————————————————————————————————————+" << std::endl;
        usleep(2000000);
        system("clear");
        return (0);
    }
    while (1)
    {
        DisplayContact();
        std::cout << "→ ";
        std::cin >> intput_str;
        if (intput_str == "EXIT")
            break;
        cpy = intput_str.c_str();
        index = atoi(cpy);
        val = checklist(index, intput_str);
        if (val == 1)
        {
            val = this->Contacts[index].ShowContact();
            system("clear");
            return (val);
        }
        else if (val == 2)
            return (2);
    }
    return (0);
}

void DisplayMenu ( void ) {
    std::cout << "+———————————————————————————————————————————————————————+" <<std::endl;
    std::cout << "| Type the index number of the contact you want to view |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "| Type EXIT to go back to the Main menu                 |" <<std::endl;
    std::cout << "+———————————————————————————————————————————————————————+" <<std::endl;
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
