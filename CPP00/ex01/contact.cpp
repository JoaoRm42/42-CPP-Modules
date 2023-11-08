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
//    std::cout << "Contact Constructor Called" << std::endl;
    return;
}

Contact::~Contact() {
//    std::cout << "Contact Destructor Called" << std::endl;
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

void Contact::ShowContact() {
    std::string str;
    system("clear");
    std::cout << "First Name: " << this->GetFirst() << std::endl;
    std::cout << "Last Name: " << this->GetLast() << std::endl;
    std::cout << "Nickname: " << this->GetNick() << std::endl;
    std::cout << "Phonenumber: " << this->GetPhone() << std::endl;
    std::cout << "Darkest Secret: " << this->GetDark() << std::endl;
    std::cout << std::endl;
    std::cout << "Press Enter to continue" << std::endl;
    std::cin >> str;
    if (str.empty())
    {
        system("clear");
        return ;
    }
    else
    {
        system("clear");
        return ;
    }
}

void Contact::setValues(std::string Fn, std::string Ln, std::string Nick, std::string Phone, std::string Ds) {
    this->Firstname = Fn;
    this->Lastname = Ln;
    this->Nickname = Nick;
    this->Phonenumber = Phone;
    this->DarkestSecret = Ds;
    return ;
}