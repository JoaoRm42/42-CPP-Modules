//
// Created by joaoped2 on 3/21/24.
//

#ifndef CPP_MODULES_42_PMERGEME_HPP
#define CPP_MODULES_42_PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <iterator>
#include <climits>
#include <ctime>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
    public:
        PmergeMe();
        PmergeMe(std::vector<int> cont);
        PmergeMe(const PmergeMe &cpy);
        PmergeMe& operator=(const PmergeMe &cpy);
        ~PmergeMe();

        void sortCont();
        void printDeque();
        void mergeDec(std::deque<int> &vector);
        void sortMergeDec(std::deque<int> &left, std::deque<int> &right, std::deque<int> &vector);
};


#endif //CPP_MODULES_42_PMERGEME_HPP
