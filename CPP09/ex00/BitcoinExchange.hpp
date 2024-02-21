//
// Created by Neddy on 20/02/2024.
//

#ifndef CPP_MODULES_42_BITCOINEXCHANGE_HPP
#define CPP_MODULES_42_BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> btc;
        std::string _fdOut;
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange& operator=(const BitcoinExchange &cpy);

    public:
        BitcoinExchange();
        BitcoinExchange(std::string fdOut);
        ~BitcoinExchange();

        void setNameFile(std::string name);
        std::string getNameFile();

        void printBTCMap();

        bool checkerDigits(const std::string &name);
        bool checkerLeapYear(int year);
        void checkerInput();
        void checkerLine(std::string &line);
        bool checkerPipes(std::string &line);
        bool checkerDate(std::string &line);
        bool checkerYear(std::string &year, std::string &date);
        bool checkerMonth(std::string &month);
        bool checkerDay(std::string &year, std::string &month, std::string &day);
        bool checkerValue(std::string &line, std::string &date);

        void csvReader();
        void BTCValueConverter();
};


#endif //CPP_MODULES_42_BITCOINEXCHANGE_HPP
