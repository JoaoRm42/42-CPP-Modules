//
// Created by Neddy on 20/02/2024.
//

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _fdOut("Default") {
    csvReader();
    checkerInput();
}

BitcoinExchange::BitcoinExchange(std::string fdOut) : _fdOut(fdOut) {
    csvReader();
    checkerInput();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
    (void)cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy) {
    (void)cpy;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {

}

void BitcoinExchange::setNameFile(std::string name) {
    _fdOut = name;
}

std::string BitcoinExchange::getNameFile() {
    return (_fdOut);
}

