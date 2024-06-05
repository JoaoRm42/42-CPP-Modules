/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:21:39 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/05 18:05:37 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _string() {}

RPN::RPN(const char **av) : _string() {
    fill_stack(av);
}

RPN::RPN(const RPN &obj) {
    (void)obj;
}

RPN &RPN::operator=(const RPN &obj) {
    (void)obj;
    return(*this);
}

RPN::~RPN() {}

void RPN::printStack(const std::stack<std::string> &stack, const char *name) {
    std::stack<std::string> copy = stack;
    while (!copy.empty()) {
        std::cout << "Elements in " << name << ": " << copy.top() << std::endl;
        copy.pop();
    }
}

void RPN::tokenizeAndPush(std::stack<std::string> &stack, const std::string &input) {
    std::istringstream iss(input);
    std::stack<std::string> copy;
    std::string token;
    size_t splitPosition = 1;
    while (iss >> token) {
        if (token.length() != 1) {
            std::string tmp = token.substr(0, splitPosition);
            std::string tmp2 = token.substr(splitPosition);
            copy.push(tmp);
            copy.push(tmp2);
        }
        else
            copy.push(token);
    }
    while (!copy.empty()) {
        stack.push(copy.top());
        copy.pop();
    }
}

void RPN::filler() {
    for (size_t i = 0; i <= 9; ++i) {
        std::stringstream ss;
        ss << i;
        this->_validation.push(ss.str());
    }
}

void RPN::fill_stack(const char **av) {
    tokenizeAndPush(this->_string, av[1]);
    filler();
    this->_validation.push("+");
    this->_validation.push("-");
    this->_validation.push("*");
    this->_validation.push("/");
    if (!check_stack_valid())
        return ;
    if (!execute_calculus())
        return ;
}

int RPN::check_stack_valid() {
    std::stack<std::string> copy = this->_string;
    while (!copy.empty()) {
        bool found = false;
        std::stack<std::string> copy2 = this->_validation;

        while (!copy2.empty()) {
            if (copy2.top() == copy.top()) {
                found = true;
                break;
            }
            copy2.pop();
        }
        if (!found) {
            std::cout << "Error" << std::endl;
            return (0);
        }
        copy.pop();
    }
    return (1);
}

int RPN::check_stack_digit(std::stack<std::string> &tmp) {
    if (!tmp.empty()) {
        const std::string& topElement = tmp.top();

        bool isnumber = true;
        for (size_t i = 0; i < topElement.length(); ++i) {
            if (!std::isdigit(topElement[i])) {
                isnumber = false;
                break;
            }
        }
        if (!isnumber)
            return 0;
    }
    return 1;
}

void RPN::clean_stack(std::stack<std::string> &stack, std::string &first, std::string &second) {
    stack.pop();
    second = stack.top();
    stack.pop();
    first = stack.top();
    stack.pop();
    return ;
}

int RPN::stringToInt(const std::string& str) {
    std::istringstream iss(str);
    int result;
    iss >> result;
    return result;
}

std::string RPN::intToString(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

int RPN::check_validation_calc(std::stack<std::string> &calc, std::stack<std::string> &tmp) {
    std::stack<std::string> tmp2 = tmp;
    std::stack<std::string> calc_tmp = calc;
    calc_tmp.push(tmp2.top());
    if (isdigit(stringToInt(calc_tmp.top())) == 1)
        return (0);
    tmp2.pop();
    calc_tmp.push(tmp2.top());
    if (isdigit(stringToInt(calc_tmp.top())) == 1)
        return (0);
    return(1);
}

int RPN::check_final(std::stack<std::string> &calc, std::stack<std::string> &tmp, std::string &first, std::string &second) {
    if (tmp.empty() && isdigit(stringToInt(first)) && isdigit(stringToInt(second)) && !isdigit(stringToInt(calc.top())))
        return 1;
    else
        return 0;
}

int RPN::execute_calculus() {
    std::stack<std::string> calc;
    std::stack<std::string> tmp = this->_string;
    std::string first;
    std::string second;
    std::string total;
    int math_t;
    if (check_validation_calc(calc, tmp) == 0) {
        std::cout << "Error" << std::endl;
        return(0);
    }
    while (!tmp.empty()) {
        calc.push(tmp.top());
        if (calc.top() == "+") {
            tmp.pop();
            if (calc.size() >= 2 && tmp.empty()) {
                if (check_final(calc, tmp, first, second)) {
                    std::cout << "Error" << std::endl;
                    return(0);
                }
            }
            clean_stack(calc, first, second);
            math_t = stringToInt(first) + stringToInt(second);
            calc.push(intToString(math_t));
        } else if (calc.top() == "/") {
            tmp.pop();
            if (calc.size() >= 2 && tmp.empty()) {
                if (check_final(calc, tmp, first, second)) {
                    std::cout << "Error" << std::endl;
                    return(0);
                }
            }
            clean_stack(calc, first, second);
            math_t = stringToInt(first) / stringToInt(second);
            calc.push(intToString(math_t));
        } else if (calc.top() == "*") {
            tmp.pop();
            if (calc.size() >= 2 && tmp.empty()) {
                if (check_final(calc, tmp, first, second)) {
                    std::cout << "Error" << std::endl;
                    return(0);
                }
            }
            clean_stack(calc, first, second);
            math_t = stringToInt(first) * stringToInt(second);
            calc.push(intToString(math_t));
        } else if (calc.top() == "-") {
            tmp.pop();
            if (calc.size() >= 2 && tmp.empty()) {
                if (check_final(calc, tmp, first, second)) {
                    std::cout << "Error" << std::endl;
                    return(0);
                }
            }
            clean_stack(calc, first, second);
            math_t = stringToInt(first) - stringToInt(second);
            calc.push(intToString(math_t));
        } else {
            tmp.pop();
        }
    }
    std::cout << calc.top() << std::endl;
    return (1);
}