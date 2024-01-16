//
// Created by Juanito on 15/01/2024.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main() {
    Intern someRandomIntern;
    AForm* rrf;

    try{
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << rrf->getName() << std::endl;
        delete rrf;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try{
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        std::cout << rrf->getName() << std::endl;
        delete rrf;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try{
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        std::cout << rrf->getName() << std::endl;
        delete rrf;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try{
        rrf = someRandomIntern.makeForm("anything", "Bender");
        delete rrf;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}

