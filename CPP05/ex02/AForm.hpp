//
// Created by Juanito on 15/01/2024.
//

#ifndef CPP_MODULES_42_AFORM_HPP
#define CPP_MODULES_42_AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _reqGrade;
        const int _execGrade;
    public:
        AForm();
        AForm(std::string name, int reqGrade, int execGrade);
        AForm(AForm const &obj);
        AForm &operator = (AForm const &obj);
        virtual ~AForm();


        void beSigned(Bureaucrat const &sign);
        void exec(Bureaucrat const &exec) const;
        virtual void typeExecute() const = 0;

        std::string getName() const;
        bool getSigned() const;
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
        class notSigned : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &out, AForm &obj);

#endif //CPP_MODULES_42_AFORM_HPP
