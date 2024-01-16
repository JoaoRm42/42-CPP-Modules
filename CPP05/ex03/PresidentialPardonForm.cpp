//
// Created by Juanito on 16/01/2024.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialForm", 25, 5), _target("Default") {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialForm", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), _target(obj._target) {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this == &obj)
        return (*this);
    _target = obj._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

std::string PresidentialPardonForm::getTarget() const {
    return (this->_target);
}

void PresidentialPardonForm::typeExecute() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
