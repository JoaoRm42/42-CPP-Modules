//
// Created by joaoped2 on 3/21/24.
//

#include "PmergeMe.hpp"

bool isDigit(const std::string str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            return (false);
        }
    }
    return (true);
}

int main(int ac, char **av) {

    if (ac < 2) {
        std::cout << "Error: Bad Input" << std::endl;
        return (1);
    }

    for (int i = 1; i < ac; i++) {
        if (isDigit(av[i]) == false) {
            std::cout << "Error: Input arguments can only contain positive integers!" << std::endl;
            return (1);
        }
    }

    std::vector<int> tmp;
    for (int i = 1; i < ac; i++) {
        if (atol(av[i]) < INT_MIN || atol(av[i]) > INT_MAX) {
            std::cout << "Error: Input arguments can't be greater than INT_MAX or lower than INT_MIN" << std::endl;
            return (1);
        }
        else {
            tmp.push_back(atoi(av[i]));
        }
    }

    PmergeMe program(tmp);
}