//
// Created by Neddy on 07/02/2024.
//

#include "easyfind.hpp"

int main() {
    std::vector<int> container;
    std::vector<int> container2;

    try {

        //First Container
        container.push_back(1);
        container.push_back(2);
        container.push_back(3);
        container.push_back(4);
        container.push_back(5);
        container.insert(container.begin() + 5, 6);

        easyfind(container, 5);
        for (size_t i = 0; i < container.size(); ++i) {
            std::cout << container[i] << " ";
        }
        std::cout << std::endl;
        for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        //Second Container
        container2.push_back(7);
        container2.push_back(8);
        container2.push_back(9);
        container2.push_back(10);
        container2.push_back(11);
        container2.insert(container2.begin() + 5, 12);

        easyfind(container2, 12);
        for (size_t i = 0; i < container2.size(); ++i) {
            std::cout << container2[i] << " ";
        }
        std::cout << std::endl;
        for (std::vector<int>::iterator it = container2.begin(); it != container2.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        easyfind(container2, 2);
    }
    catch (const std::exception &t) {
        std::cout << t.what() << std::endl;
    }
}