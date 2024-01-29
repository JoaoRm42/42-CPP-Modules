//
// Created by Juanito on 29/01/2024.
//

#ifndef CPP_MODULES_42_ITER_HPP
#define CPP_MODULES_42_ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int len, void (*f)(T& element)){
    for (int i = 0; i < len; i++) {
        f(array[i]);
        if (i + 1 != len)
            std::cout << " ";
    }
}


template <class T>
void printArrayByIter(T &element) {
    std::cout << element;
}


#endif //CPP_MODULES_42_ITER_HPP
