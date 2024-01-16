//
// Created by Juanito on 15/01/2024.
//

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat one;
    Bureaucrat two("Segundo", 1);

    std::cout << one << std::endl;
    std::cout << two << std::endl;

    try{
        two.increaseGrade();
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    two.decreaseGrade();
    std::cout << two << std::endl;

    try{
        one.decreaseGrade();
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    one.increaseGrade();
    std::cout << one << std::endl;

    try{
        Bureaucrat("test", -150);
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }

    try{
        Bureaucrat("Test", 1500);
    } catch (std::exception &t) {
        std::cout << t.what() << std::endl;
    }
    return (0);
}

