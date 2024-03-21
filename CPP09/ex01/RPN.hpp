//
// Created by Neddy on 20/03/2024.
//

#ifndef CPP_MODULES_42_RPN_HPP
#define CPP_MODULES_42_RPN_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stack>

class RPN {
    private:
            std::string _expression;
            std::stack<double> _stack;
            RPN(const RPN& cpy);
            RPN& operator=(const RPN& cpy);

    public:
        RPN();
        RPN(std::string input);
        ~RPN();

        void expressionSetter(std::string exp);
        std::string expressionGetter();
        bool expressionChecker();
        void execRPN();

        class WrongExpressionException : public std::exception
        {
            public:
                virtual const char *what() const throw(){return "Exception: Incorrect expression!\nPlease try again!";}
        };

};


#endif //CPP_MODULES_42_RPN_HPP
