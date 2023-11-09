/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:35 by joaoped2          #+#    #+#             */
/*   Updated: 2023/11/08 17:36:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

std::string Contact::GetFirst() {
    return (Contact::Firstname);
}

std::string Contact::GetLast() {
    return (Contact::Lastname);
}

std::string Contact::GetNick() {
    return (Contact::Nickname);
}

std::string Contact::GetPhone() {
    return (Contact::Phonenumber);
}

std::string Contact::GetDark() {
    return (Contact::DarkestSecret);
}

std::string Contact::SetString(std::string str) {
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

std::string PadWithSpaces(const std::string& input, int maxLength) {
    std::string padded, truncated;
    if (input.length() <= maxLength)
    {
        int spacesToAdd = maxLength - input.length();
        padded = input;
        padded.append(spacesToAdd, ' ');
        return padded;
    }
    else
    {
        truncated = input.substr(0, maxLength - 1) + '.';
        return truncated;
    }
}

void Contact::ContactShow( void ) {
    std::cout << "+—————————————————————————————————————————+" << std::endl;
    std::cout << "| First Name:     " << PadWithSpaces(this->GetFirst(), 24) << "|" << std::endl;
    std::cout << "| Last Name:      " << PadWithSpaces(this->GetLast(), 24) << "|" << std::endl;
    std::cout << "| Nickname:       " << PadWithSpaces(this->GetNick(), 24) << "|" << std::endl;
    std::cout << "| Phonenumber:    " << PadWithSpaces(this->GetPhone(), 24) << "|" << std::endl;
    std::cout << "| Darkest Secret: " << PadWithSpaces(this->GetDark(), 24) << "|" << std::endl;
    std::cout << "+—————————————————————————————————————————+" << std::endl;
    std::cout << std::endl;
    std::cout << "Type EXIT to leave the contact information" << std::endl;
    std::cout << "→ ";
}

int Contact::ShowContact() {
    std::string str;
    system("clear");
    ContactShow();
    while (1)
    {
        std::getline(std::cin, str);
        if (str == "EXIT")
            break;
        else if (std::cin.eof())
            return (2);
        else {
            system("clear");
            ContactShow();
        }
    }
    return (0);
}

int Contact::CheckValues( std::string Fn, std::string Ln, std::string Nick, std::string Phone, std::string Ds ) {
    if (Fn == "" || Ln == "" || Nick == "" || Phone == "" || Ds == "" )
    {
        system("clear");
        std::cout << "+—————————————————————————————————————————+" << std::endl;
        std::cout << "| Error! There should not be Empty Fields |" << std::endl;
        std::cout << "+—————————————————————————————————————————+" << std::endl;
        usleep(2000000);
        system("clear");
        return (1);
    }
    return (0);
}

void Contact::SetValues(std::string Fn, std::string Ln, std::string Nick, std::string Phone, std::string Ds) {
    this->Firstname = Fn;
    this->Lastname = Ln;
    this->Nickname = Nick;
    this->Phonenumber = Phone;
    this->DarkestSecret = Ds;
    return ;
}