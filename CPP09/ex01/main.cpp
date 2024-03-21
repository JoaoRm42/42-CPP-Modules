//
// Created by Neddy on 20/03/2024.
//

#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: Wrong input!" << std::endl;
    }
    try {
        RPN testing1(av[1]);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}