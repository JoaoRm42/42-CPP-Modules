//
// Created by Neddy on 07/02/2024.
//

#include "Span.hpp"

Span::Span() : _N(0) {

}

Span::Span(unsigned int n) : _N(n) {

}

Span::Span(const Span &cpy) : _N(cpy._N), container(cpy.container) {

}

Span &Span::operator=(const Span &cpy) {
    if (this == &cpy)
        return (*this);
    container.clear();
    _N = cpy._N;
    container = cpy.container;
    return (*this);
}

Span::~Span() {

}

void Span::addNumber(int n) {
    if (container.size() >= _N)
        throw SpanMaxElements();
    container.push_back(n);
}

int Span::shortestSpan() {
    if (container.size() <= 1)
        throw NotEnoughElements();

    int min = std::numeric_limits<int>::max();
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++) {
        for (std::vector<int>::iterator it2 = container.begin(); it2 != container.end(); it2++) {
            if (it == it2)
                continue ;
            if (std::abs(*it - *it2) < min) {
                min = std::abs(*it - *it2);
                a = *it;
                b = *it2;
            }
        }
    }
    return (min);
}

int Span::longestSpan() {
    if (container.size() <= 1)
        throw NotEnoughElements();

    std::vector<int> sorting = container;
    std::sort(sorting.begin(), sorting.end());

    int min = sorting.front();
    int max = sorting.back();
    int result = max - min;

    return (result);
}

int generateNumber() {
    return (std::rand() % 10000);
}

void Span::fillContainer() {
    container.resize(this->_N);
    std::generate(this->container.begin(), this->container.end(), generateNumber);
}

void Span::printContainer() {
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}