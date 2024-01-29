//
// Created by Juanito on 29/01/2024.
//

#include "iter.hpp"

int main() {
    std::string stringArray[] = {"I", "Like", "Potatoes"};
    ::iter(stringArray, 3, &printArrayByIter);
    std::cout << std::endl;

    int intArray[] = {5, 3, 8};
    ::iter(intArray, 3, &printArrayByIter);
    std::cout << std::endl;

    char charArray[] = {'x', 'y', 'z'};
    ::iter(charArray, 3, &printArrayByIter);
    std::cout << std::endl;

    return (0);
}