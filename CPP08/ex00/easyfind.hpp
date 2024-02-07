//
// Created by Neddy on 07/02/2024.
//

#ifndef CPP_MODULES_42_EASYFIND_HPP
#define CPP_MODULES_42_EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return ("Error: Number not found!");
        }
};

template <typename T>
void easyfind(T const &container, int numbers) {
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), numbers);
    if (it == container.end())
        throw NotFoundException();
    else
        std::cout << "Number found: " << *it << std::endl;
}

#endif //CPP_MODULES_42_EASYFIND_HPP
