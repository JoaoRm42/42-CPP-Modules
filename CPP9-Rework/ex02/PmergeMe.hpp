/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:14:04 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/06 10:52:57 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

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
        int stringToInt(const std::string& str);
};

#endif