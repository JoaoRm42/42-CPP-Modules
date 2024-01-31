//
// Created by Juanito on 29/01/2024.
//

#ifndef CPP_MODULES_42_ARRAY_HPP
#define CPP_MODULES_42_ARRAY_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h>

template<class T>
class Array {
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int size);
        Array(Array const &cpy);
        ~Array();

        Array& operator=(const Array &cpy);
        T& operator[](unsigned int i);
        unsigned int size()const;
};

#include "Array.tpp"
#endif //CPP_MODULES_42_ARRAY_HPP
