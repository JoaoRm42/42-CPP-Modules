//
// Created by joaoped2 on 1/18/24.
//

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Invalid Arguments!" << std::endl;
    }
    ScalarConverter::convert(av[1]);
    return (0);
}