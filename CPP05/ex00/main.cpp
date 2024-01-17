//
// Created by Juanito on 15/01/2024.
//

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat Porto;
    Bureaucrat Lisboa("Lisboa", 1);

    std::cout << Porto << std::endl;
    std::cout << Lisboa << std::endl;

    try{
        Lisboa.increaseGrade();
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    Lisboa.decreaseGrade();
    std::cout << Lisboa << std::endl;

    try{
        Porto.decreaseGrade();
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    Porto.increaseGrade();
    std::cout << Porto << std::endl;

    try{
        Bureaucrat("wrong", -150);
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }

    try{
        Bureaucrat("Wrong", 1500);
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    return (0);
}

