/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:14:04 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/06 14:17:40 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <ctime>

class PmergeMe {
    private:
        std::vector<std::string> _vector;
        std::deque<std::string> _deque;
        PmergeMe();
        PmergeMe(const PmergeMe &obj);
        PmergeMe& operator=(const PmergeMe &obj);
    public:
        PmergeMe(char **av);
        ~PmergeMe();
        void fill_containers(char **av);
        void interface(char **av);
        int check_valid_containers();
        void print_vector(const std::vector<int> &vector);
        void print_deque(const std::deque<int> &deque);
        bool isInteger(const std::string& str);
        void insertSortedVector(std::vector<int>& vec, int num);
        void insertSortedDeque(std::deque<int>& vec, int num);
        void fordJohnsonSortVector(std::vector<int>& arr);
        void fordJohnsonSortDeque(std::deque<int>& arr);
        std::vector<int> convertToIntVector(const std::vector<std::string>& stringVector);
        std::deque<int> convertToIntDeque(const std::deque<std::string>& stringDeque);
        void send_vector();
        void send_deque();
};

#endif