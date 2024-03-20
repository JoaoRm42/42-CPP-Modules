//
// Created by joaoped2 on 3/18/24.
//

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error!" << std::endl;
    }
    try {
        BitcoinExchange btc(av[1]);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}