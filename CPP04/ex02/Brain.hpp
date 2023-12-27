//
// Created by joaoped2 on 12/27/23.
//

#ifndef CPP_MODULES_42_BRAIN_HPP
#define CPP_MODULES_42_BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& cpy);
        Brain& operator = (const Brain& cpy);
        ~Brain();
};

#endif //CPP_MODULES_42_BRAIN_HPP
