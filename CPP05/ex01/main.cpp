//
// Created by Juanito on 15/01/2024.
//

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat	Porto;
    Bureaucrat	Lisboa("lisboa", 1);
    Bureaucrat	Faro("porto", 75);
    Form		exam1("exam1", 1, 100);
    Form		exam2("exam2", 20, 100);
    Form		exam3("exam3", 80, 100);

    std::cout << Porto << std::endl;
    std::cout << Lisboa << std::endl;
    std::cout << Faro << std::endl;
    std::cout << exam1 << std::endl;
    exam1.beSigned(Lisboa);
    Lisboa.signForm(exam1);
    Lisboa.signForm(exam2);
    std::cout << std::endl;
    std::cout << std::endl;

    try{
        Faro.signForm(exam2);
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    try{
        Porto.signForm(exam1);
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    std::cout << exam3 << std::endl;
    try{
        Faro.signForm(exam3);
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    std::cout << exam3 << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    try{
        Bureaucrat	Madeira("Madeira", 0);
        try{
            Madeira.signForm(exam2);
        } catch (std::exception &t) {
            std::cout << t.what() << std::endl;
        }
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    try{
        Bureaucrat	Madeira("Madeira", 155);
        try{
            Madeira.signForm(exam2);
        } catch (std::exception &t) {
            std::cout << t.what() << std::endl;
        }
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    return (0);
}

