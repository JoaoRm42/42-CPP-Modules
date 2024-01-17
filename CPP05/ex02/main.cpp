//
// Created by Juanito on 15/01/2024.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    Bureaucrat	Porto;
    Bureaucrat	Lisboa("Lisboa", 1);
    Bureaucrat	Faro("Faro", 75);
    PresidentialPardonForm pres("Presidente");
    RobotomyRequestForm robot("Robô");
    ShrubberyCreationForm tree("Árvore");

    try{
        Lisboa.signForm(pres);
        pres.exec(Lisboa);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try{
        Faro.signForm(robot);
        robot.exec(Faro);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try{
        Faro.signForm(tree);
        tree.exec(Faro);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try{
        robot.exec(Porto);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        robot.exec(Lisboa);
        Lisboa.signForm(robot);
        robot.exec(Lisboa);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Lisboa.signForm(robot);
        robot.exec(Lisboa);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat Madeira ("Madeira", 150);
    Bureaucrat Açôres ("Açôres", 10);
    PresidentialPardonForm pres2("Obama");

    try {
        Madeira.execForm(pres);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Açôres.execForm(pres2);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Açôres.signForm(pres2);
        Açôres.execForm(pres2);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

