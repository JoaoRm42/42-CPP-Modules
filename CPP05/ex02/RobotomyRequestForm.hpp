//
// Created by Juanito on 16/01/2024.
//

#pragma once

#ifndef CPP_MODULES_42_ROBOTOMYREQUESTFORM_HPP
#define CPP_MODULES_42_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &obj);
        RobotomyRequestForm& operator=(RobotomyRequestForm const &obj);
        ~RobotomyRequestForm();

        virtual void typeExecute() const;
        std::string getTarget() const;
};


#endif //CPP_MODULES_42_ROBOTOMYREQUESTFORM_HPP
