//
// Created by joaoped2 on 3/21/24.
//

#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "Error: Bad Input" << std::endl;
        return (1);
    }

    for (int i = 1; i < ac; i++) {
        if (isdigit(av[i]) == false) {
            std::cout << "Error: Input can only contain positive integers!" << std::endl;
            return (1);
        }
    }

    std::vector<int> tmp;
    for (int i = 1; i < ac; i++) {
        if (atol(av[i]) < INT_MIN)
    }
}