//
// Created by Juanito on 29/01/2024.
//

#ifndef CPP_MODULES_42_ARRAY_TPP
#define CPP_MODULES_42_ARRAY_TPP

#include "Array.hpp"

template<class T>
Array<T>::Array() : _array(new T[0]), _size(0) {
    return ;
}

template<class T>
Array<T>::Array(unsigned int size) : _size(size) {
    if ( size < 0 )
        throw std::out_of_range("Index out of range!");

    this->_array = new T[size];
    for (unsigned int i = 0; i < _size ; i++)
        this->_array[i] = T();
    return ;
}

template<class T>
Array<T>::Array(Array<T> const & cpy) {
    this->_array = NULL;
    *this = cpy;
    return ;
}

template<class T>
Array<T>::~Array() {
    delete [] this->_array;
    return ;
}

template<class T>
Array<T> & Array<T>::operator=(Array<T> const & cpy) {
    if (this != &cpy) {
        this->_size = cpy._size;
        delete [] this->_array;
        this->_array = new T[this->_size];
        for (unsigned int i = 0; i < cpy._size; i++)
            this->_array[i] = cpy._array[i];
    }
    return (*this);
}

template<class T>
T & Array<T>::operator[](unsigned int i) {
    if (i < 0 || i >= this->_size)
        throw std::out_of_range("Index out of range!");
    return (this->_array[i]);
}

template<class T>
unsigned int Array<T>::size() const {
    return (this->_size);
}

#endif