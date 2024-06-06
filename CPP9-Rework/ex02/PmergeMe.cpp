/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:14:06 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/06 10:54:00 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(), _deque() {}

PmergeMe::PmergeMe(char **av) : _vector(), _deque() {
    interface(av);
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
    (void)obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) { 
    (void)obj;
    return(*this);
}

PmergeMe::~PmergeMe() {}

void print_vector(const std::vector<std::string> &vector) {
    for (std::vector<int>::size_type i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

void print_deque(const std::deque<std::string> &deque) {
    for (std::deque<int>::size_type i = 0; i < deque.size(); ++i) {
        std::cout << deque[i] << " ";
    }
    std::cout << std::endl;
}

bool isInteger(const std::string& s) {
    if (s.empty())
        return false;
    std::string::const_iterator it = s.begin();
    if (*it == '-' || *it == '+')
        return false;
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return it == s.end();
}

int PmergeMe::check_valid_containers() {
    for (std::vector<int>::size_type i = 0; i < this->_vector.size(); ++i) {
        if (!isInteger(this->_vector[i])) {
            std::cout << "Error" << std::endl;
            return (1);
        }
    }
    return (0);
}


void PmergeMe::fill_containers(char **av) {
    for (size_t i = 1; av[i]; ++i) {
        this->_vector.push_back(av[i]);
        this->_deque.push_back(av[i]);
    }
}

void PmergeMe::interface(char **av) {
    fill_containers(av);
    if (!check_valid_containers())
        return ;
    
    // print_vector(this->_vector);
    // print_deque(this->_deque);
}