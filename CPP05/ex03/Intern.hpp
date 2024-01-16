//
// Created by Juanito on 16/01/2024.
//

#pragma once

#ifndef CPP_MODULES_42_INTERN_HPP
#define CPP_MODULES_42_INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class Bureaucrat;

class Intern {
    public:
        Intern();
        Intern(Intern const &obj);
        Intern& operator=(Intern const &obj);
        ~Intern();

        AForm* makeForm(std::string name, std::string target);
        AForm* robotForm(std::string target);
        AForm* presidentForm(std::string target);
        AForm* shrubberyForm(std::string target);
    class FormNotFoundException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

};


#endif //CPP_MODULES_42_INTERN_HPP
