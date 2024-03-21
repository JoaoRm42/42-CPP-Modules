//
// Created by Neddy on 20/03/2024.
//

#include "RPN.hpp"

RPN::RPN() : _expression("Default") {
    execRPN();
}

RPN::RPN(const RPN &cpy) {
    (void)cpy;
}

RPN &RPN::operator=(const RPN &cpy) {
    (void)cpy;
    return(*this);
}

RPN::~RPN() {

}

RPN::RPN(std::string input) : _expression(input) {
    if (this->expressionChecker() == false) {
        throw WrongExpressionException();
    }
    execRPN();
}

void RPN::expressionSetter(std::string exp) {
    this->_expression = exp;
}

std::string RPN::expressionGetter() {
    return (this->_expression);
}

bool RPN::expressionChecker() {
    std::istringstream exp(_expression);
    std::string index;

    while (exp >> index) {
        if (!((index.size() == 1 && isdigit(index[0])) || (index.size() == 1 && std::string("+-*/").find(index[0]) != std::string::npos)))
            return (false);
    }

    return (true);
}

void RPN::execRPN() {
    std::istringstream exp(_expression);
    std::string index;

    while (exp >> index) {
        if (isdigit(index[0]))
            _stack.push(std::atof(index.c_str()));
        else {
            if (_stack.empty())
                throw WrongExpressionException();
            double val2 = _stack.top();
            _stack.pop();
            if  (_stack.empty())
                throw WrongExpressionException();
            double val1 = _stack.top();
            _stack.pop();

            if(index == "+")
                _stack.push(val1 + val2);
            else if(index == "-")
                _stack.push(val1 - val2);
            else if(index == "*")
                _stack.push(val1 * val2);
            else if(index == "/")
                _stack.push(val1 / val2);
            else
                throw WrongExpressionException();
        }
    }
    if (!_stack.empty())
        std::cout << _stack.top() << std::endl;
}