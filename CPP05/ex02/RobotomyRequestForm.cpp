//
// Created by Juanito on 16/01/2024.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotForm", 72, 45) , _target("Default") {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    if (this == &obj)
        return (*this);
    _target = obj._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

std::string RobotomyRequestForm::getTarget() const {
    return (this->_target);
}

void RobotomyRequestForm::typeExecute() const {
    std::cout << "DRILLING NOISES" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->_target << " has failed to be robotomized" << std::endl;
}

