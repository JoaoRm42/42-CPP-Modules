/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:21:41 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/06 10:01:28 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <cctype>

class RPN {
    private:
        std::stack<std::string> _string;
        std::stack<std::string> _validation;
        RPN();
        RPN(const RPN &obj);
        RPN& operator=(const RPN &obj);
    public:
        RPN(const char **av);
        ~RPN();
        void fill_stack(const char **av);
        void tokenizeAndPush(std::stack<std::string>& stack, const std::string &input);
        void printStack(const std::stack<std::string> &stack, const char *name);
        int clean_stack(std::stack<std::string> &stack, std::string &first, std::string &second);
        int check_stack_valid();
        int execute_calculus();
        void filler();
        std::string intToString(int number);
        int stringToInt(const std::string& str);
        int check_validation_calc(std::stack<std::string> &calc, std::stack<std::string> &tmp);
        int check_final(std::stack<std::string> &calc, std::stack<std::string> &tmp, std::string &first, std::string &second);
        int calc_exec(std::stack<std::string> &tmp, std::stack<std::string> &calc, std::string &first, std::string &second, const char *signal);
        void check_operator(int (*&operation)(int, int), const char *signal);
        int check_av(const char **av);
};

#endif
