//
// Created by Juanito on 15/01/2024.
//

#ifndef CPP_MODULES_42_BUREAUCRAT_HPP
#define CPP_MODULES_42_BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &obj);
        Bureaucrat &operator = (Bureaucrat const &obj);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void increaseGrade();
        void decreaseGrade();
        void		signForm(Form &form);
        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);


#endif //CPP_MODULES_42_BUREAUCRAT_HPP
