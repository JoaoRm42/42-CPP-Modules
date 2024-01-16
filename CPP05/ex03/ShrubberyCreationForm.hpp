//
// Created by Juanito on 16/01/2024.
//

#ifndef CPP_MODULES_42_SHRUBBERYCREATIONFORM_HPP
#define CPP_MODULES_42_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &obj);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const &obj);
        ~ShrubberyCreationForm();

        virtual void typeExecute() const;
        std::string getTarget() const;
};

#endif //CPP_MODULES_42_SHRUBBERYCREATIONFORM_HPP
