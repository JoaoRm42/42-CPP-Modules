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

    public:
        BitcoinExchange();
        BitcoinExchange(std::string fdOut);
        ~BitcoinExchange();
};


#endif //CPP_MODULES_42_BITCOINEXCHANGE_HPP
