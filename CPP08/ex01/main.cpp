//
// Created by Neddy on 07/02/2024.
//

#include "Span.hpp"

int main() {

    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        sp.addNumber(2);
    }
    catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try {
        Span container(20);

        container.fillContainer();
        container.printContainer();

        std::cout << container.shortestSpan() << std::endl;
        std::cout << container.longestSpan() << std::endl;
    }
    catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}