//
// Created by Juanito on 16/01/2024.
//

#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern &obj) {
    *this = obj;
}

Intern &Intern::operator=(const Intern &obj) {
    if (this == &obj)
        return (*this);
    return (*this);
}

Intern::~Intern() {

}

AForm *Intern::robotForm(std::string target) {
    return(new RobotomyRequestForm(target));
}

AForm *Intern::presidentForm(std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm *Intern::shrubberyForm(std::string target) {
    return (new ShrubberyCreationForm(target));
}

const char* Intern::FormNotFoundException::what() const throw() {
    return ("Form not found!");
}

AForm *Intern::makeForm(std::string name, std::string target) {
    std::string formNames[3] = {"robotomy request", "presidential pardon", "shruberry creation"};
    AForm* (Intern::*formFuncs[3])(std::string) = {&Intern::robotForm, &Intern::presidentForm, &Intern::shrubberyForm};
    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return ((this->*formFuncs[i])(target));
        }
    }
    throw Intern::FormNotFoundException();
}