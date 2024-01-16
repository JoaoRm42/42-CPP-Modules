//
// Created by Juanito on 15/01/2024.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    Bureaucrat	one;
    Bureaucrat	two("Segundo", 1);
    Bureaucrat	three("Terceiro", 75);
    PresidentialPardonForm pres("Presidente");
    RobotomyRequestForm robot("robot");
    ShrubberyCreationForm tree("tree");

    try{
        two.signForm(pres);
        pres.exec(two);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try{
        three.signForm(robot);
        robot.exec(three);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try{
        three.signForm(tree);
        tree.exec(three);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try{
        robot.exec(one);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        robot.exec(two);
        two.signForm(robot);
        robot.exec(two);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        two.signForm(robot);
        robot.exec(two);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat four ("Quarto", 150);
    Bureaucrat five ("Quinto", 10);
    PresidentialPardonForm pres2("Presidente2");

    try {
        four.execForm(pres);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        five.execForm(pres2);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        five.signForm(pres2);
        five.execForm(pres2);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

