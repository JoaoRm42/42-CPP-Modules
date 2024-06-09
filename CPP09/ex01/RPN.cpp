/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:21:39 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/06 11:50:54 by joaoped2         ###   ########.fr       */
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

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

void RPN::printStack(const std::stack<std::string> &stack, const char *name) {
    std::stack<std::string> copy = stack;
    while (!copy.empty()) {
        std::cout << "Elements in " << name << ": " << copy.top() << std::endl;
        copy.pop();
    }
}

int RPN::clean_stack(std::stack<std::string> &stack, std::string &first, std::string &second) {
    std::string tmp = stack.top();
    stack.pop();
    second = stack.top();
    if (second == "0" && tmp == "/") {
        std::cout << "Error" << std::endl;
        return (0);
    }
    stack.pop();
    first = stack.top();
    stack.pop();
    return (1);
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
    if (calc_tmp.top() == "*" || calc_tmp.top() == "/" || calc_tmp.top() == "+" || calc_tmp.top() == "-")
        return (1);
    if (tmp.size() == 1) {
        calc.push(tmp.top());
        tmp.pop();
        return (0);
    }
    tmp2.pop();
    calc_tmp.push(tmp2.top());
    if (calc_tmp.top() == "*" || calc_tmp.top() == "/" || calc_tmp.top() == "+" || calc_tmp.top() == "-")
        return (1);
    return(0);
}

int RPN::check_final(std::stack<std::string> &calc, std::stack<std::string> &tmp, std::string &first, std::string &second) {
    if (tmp.empty() && isdigit(stringToInt(first)) && isdigit(stringToInt(second)) && !isdigit(stringToInt(calc.top())))
        return (1);
    else if (tmp.empty() && calc.size() == 2 && !isdigit(stringToInt(calc.top())))
        return (1);
    else
        return (0);
}

void RPN::check_operator(int (*&operation)(int, int), const char *signal) {
    switch (*signal) {
    case '+':
        operation = add;
        break;
    case '-':
        operation = subtract;
        break;
    case '*':
        operation = multiply;
        break;
    case '/':
        operation = divide;
        break;
    default:
        std::cerr << "Unknown operator" << std::endl;
        return ;
    }
}

int RPN::calc_exec(std::stack<std::string> &tmp, std::stack<std::string> &calc, std::string &first, std::string &second, const char *signal) {
    int (*operation)(int, int);
    int result;
    tmp.pop();
    if (calc.size() >= 2 && tmp.empty()) {
        if (check_final(calc, tmp, first, second)) {
            std::cout << "Error" << std::endl;
                return(0);
        }
    }
    check_operator(operation, signal);
    if (!clean_stack(calc, first, second))
        return (0);
    result = operation(stringToInt(first), stringToInt(second));
    calc.push(intToString(result));
    return (1);
}


int RPN::execute_calculus() {
    std::stack<std::string> calc;
    std::stack<std::string> tmp = this->_string;
    std::string first;
    std::string second;
    if (check_validation_calc(calc, tmp) != 0) {
        std::cout << "Error" << std::endl;
        return(1);
    }
    while (!tmp.empty()) {
        calc.push(tmp.top());
        if (calc.top() == "+") {
            if (!calc_exec(tmp, calc, first, second, "+"))
                return (0);
        } else if (calc.top() == "/") {
            if (!calc_exec(tmp, calc, first, second, "/"))
                return (0);
        } else if (calc.top() == "*") {
            if (!calc_exec(tmp, calc, first, second, "*"))
                return (0);
        } else if (calc.top() == "-") {
            if (!calc_exec(tmp, calc, first, second, "-"))
                return (0);
        } else if (tmp.size() == 1)
            break;
        else {
            tmp.pop();
        }
    }
    if (calc.size() != 1) {
        std::cout << "Error" << std::endl;
        return(0);
    }

    std::cout << calc.top() << std::endl;
    return (1);
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

void RPN::filler() {
    for (size_t i = 0; i <= 9; ++i) {
        std::stringstream ss;
        ss << i;
        this->_validation.push(ss.str());
    }
    this->_validation.push("+");
    this->_validation.push("-");
    this->_validation.push("*");
    this->_validation.push("/");
}

void RPN::tokenizeAndPush(std::stack<std::string> &stack, const std::string &input) {
    std::istringstream iss(input);
    std::stack<std::string> copy;
    std::string token;
    size_t splitPosition = 1;
    while (iss >> token) {
        if (token != " ") {
            if (token.length() != 1) {
                std::string tmp = token.substr(0, splitPosition);
                std::string tmp2 = token.substr(splitPosition);
                copy.push(tmp);
                copy.push(tmp2);
            }
            else
                copy.push(token);
        }
    }
    while (!copy.empty()) {
        stack.push(copy.top());
        copy.pop();
    }
}

int RPN::check_av(const char **av) {
    int i = 0;
    int num = 0;
    int operators = 0;
    while (av[1][i]) {
        char c = av[1][i];
        if (c == '+' || c == '-' || c == '*' || c == '/')
            operators++;
        else if(c >= '0' && c <= '9')
            num++;
        i++;
    }
    if (num - operators != 1)  {
        std::cout << "Error" << std::endl;
        return (1);
    }
    return (0);
}

void RPN::fill_stack(const char **av) {
    if (check_av(av))
        return ;
    tokenizeAndPush(this->_string, av[1]);
    filler();
    if (!check_stack_valid())
        return ;
    if (!execute_calculus())
        return ;
}
