//
// Created by Juanito on 16/01/2024.
//
#pragma once

#ifndef CPP_MODULES_42_PRESIDENTIALPARDONFORM_HPP
#define CPP_MODULES_42_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &obj);
        PresidentialPardonForm& operator=(PresidentialPardonForm const &obj);
        ~PresidentialPardonForm();

        virtual void typeExecute() const;
        std::string getTarget() const;
};


#endif //CPP_MODULES_42_PRESIDENTIALPARDONFORM_HPP
