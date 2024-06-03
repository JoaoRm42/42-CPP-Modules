/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:06 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/03 16:03:00 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _file("Default") {
    filereader();
}

BitcoinExchange::BitcoinExchange(const std::string &file) : _file(file) {
    filereader();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
    (void)cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy) {
    (void)cpy;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "Destructer called" << std::endl;
}

// bool BitcoinExchange::date_checker(const std::string &str) {
//     for (size_t i = 0; i < str.length(); ++i)
//         if (!isdigit(str[i]))
//             return (false);
//     return (true);
// }

void BitcoinExchange::filereader() {
    std::ifstream openfile(this->_file.c_str());

    std::string reader;
    while(std::getline(openfile, reader)) {
        std::cout << reader << std::endl;
    }
    openfile.close();
}