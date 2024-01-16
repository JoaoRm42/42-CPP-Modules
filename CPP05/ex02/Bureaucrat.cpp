//
// Created by Juanito on 15/01/2024.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade) {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this == &obj)
        return (*this);
    this->_grade = obj._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {

}

std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

void Bureaucrat::increaseGrade() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decreaseGrade() {
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::execForm(const AForm &form) {
    form.exec(*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj){
    out << "Name: " << obj.getName() << std::endl << "Grade: " << obj.getGrade() << std::endl;
    return (out);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too High!\n";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too Low!\n";
}

void		Bureaucrat::signForm(AForm &form){
    if (this->_grade <= form.getReqGrade())
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    else
        std::cout << this->getName() << " could't sign " << form.getName() << " because ";
    form.beSigned(*this);
}