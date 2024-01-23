//
// Created by joaoped2 on 1/18/24.
//

#ifndef CPP_MODULES_42_SCALARCONVERTER_HPP
#define CPP_MODULES_42_SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <string>
#include <climits>
#include <sstream>
#include <limits>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <cfloat>

enum e_type {
    DEFAULT,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NNAN,
    INF,
    NINF
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &cpy);
        ScalarConverter& operator = (ScalarConverter const &cpy);
        static int _type;
        static double _value;
    public:
        ~ScalarConverter();
        static void convert(std::string const&);
        class   NonDisplayableException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class   ImpossibleException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif //CPP_MODULES_42_SCALARCONVERTER_HPP
