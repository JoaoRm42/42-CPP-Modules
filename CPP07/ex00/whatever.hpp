//
// Created by Juanito on 29/01/2024.
//

#ifndef CPP_MODULES_42_WHATEVER_HPP
#define CPP_MODULES_42_WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T &a, T &b) {
    if (a > b)
        return (b);
    else if (a < b)
        return (a);
    else
        return(b);
}

template <typename T>
T max(T &a, T &b) {
    if (a > b)
        return (a);
    else if (a < b)
        return (b);
    else
        return(b);
}

#endif //CPP_MODULES_42_WHATEVER_HPP
