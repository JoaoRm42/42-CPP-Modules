//
// Created by Juanito on 15/01/2024.
//

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _reqGrade(1), _execGrade(150) {

}

AForm::AForm(std::string name, int reqGrade, int execGrade) : _name(name), _signed(false), _reqGrade(reqGrade), _execGrade(execGrade) {

}

AForm::AForm(const AForm &obj) : _name(obj._name), _signed(obj._signed), _reqGrade(obj._reqGrade), _execGrade(obj._execGrade) {

}

AForm &AForm::operator=(const AForm &obj) {
    if (this == &obj)
        return (*this);
    this->_signed = obj._signed;
    return (*this);
}

AForm::~AForm() {

}

void AForm::beSigned(const Bureaucrat &sign) {
    if (sign.getGrade() > this->_reqGrade)
        throw GradeTooLowException();
    this->_signed = true;
}

std::string AForm::getName() const {
    return (this->_name);
}

bool AForm::getSigned() const {
    return (this->_signed);
}

int AForm::getReqGrade() const {
    return (this->_reqGrade);
}

int AForm::getExecGrade() const {
    return (this->_execGrade);
}

const char	*AForm::GradeTooHighException::what() const throw(){
    return ("Grade too High to sign\n");
}

const char	*AForm::GradeTooLowException::what() const throw(){
    return ("Grade too Low to sign\n");
}

const char *AForm::notSigned::what() const throw() {
    return ("Form isn't signed\n");
}

void AForm::exec(const Bureaucrat &exec) const {
    if (this->getReqGrade() < exec.getGrade())
        throw GradeTooLowException();
    else if (!this->getSigned())
        throw AForm::notSigned();
    this->typeExecute();
}

std::ostream	&operator<<(std::ostream &out, AForm &obj){
    out << "Form name: " << obj.getName() << std::endl;
    out << "Is signed: " << obj.getSigned() << std::endl;
    out << "Required grade: " << obj.getReqGrade() << std::endl;
    out << "Execute grade: " << obj.getExecGrade() << std::endl;
    return out;
}