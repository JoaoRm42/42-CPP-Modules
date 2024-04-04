//
// Created by Neddy on 07/02/2024.
//

#ifndef CPP_MODULES_42_SPAN_HPP
#define CPP_MODULES_42_SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>

class Span {
    private:
        unsigned int _N;
        std::vector<int> container;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &cpy);
        Span& operator = (Span const &cpy);
        ~Span();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void fillContainer();
        void printContainer();

    class SpanMaxElements : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("Error: Container is full!");
            }
    };

    class NotEnoughElements : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("Error: Container doesn't have enough elements!");
            }
    };
};
int generateNumber();

#endif //CPP_MODULES_42_SPAN_HPP
