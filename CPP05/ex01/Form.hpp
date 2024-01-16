//
// Created by Juanito on 15/01/2024.
//

#ifndef CPP_MODULES_42_FORM_HPP
#define CPP_MODULES_42_FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _reqGrade;
        const int _execGrade;
    public:
        Form();
        Form(std::string name, int reqGrade, int execGrade);
        Form(Form const &obj);
        Form &operator = (Form const &obj);
        ~Form();
        void beSigned(Bureaucrat const &sign);
        std::string getName() const;
        bool getSigned();
        int getReqGrade() const;
        int getExecGrade() const;
        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &out, Form &obj);

#endif //CPP_MODULES_42_FORM_HPP
