//
// Created by joaoped2 on 12/27/23.
//

#include "Brain.hpp"

Brain::Brain() {
    std::string ideas[] = {
            "Doritos",
            "Oreos",
            "Pringles",
            "Reese’s Peanut Butter Cups",
            "Goldfish",
            "Cheetos",
            "M&Ms",
            "Cheez-Its",
            "Gummy Bears",
            "Fritos",
    };
    long unsigned int i = 0;
    for(int j = 0; j < 100; j++) {
        if (i == 10)
            i = 0;
        this->ideas[j] = ideas[i];
        i++;
    }
    std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::Brain(const Brain &cpy) {
    *this = cpy;
    std::cout << "Brain Copy Constructor Called" << std::endl;
}

Brain &Brain::operator=(const Brain &cpy) {
    for(int i = 0; i < 100; i++) {
        this->ideas[i] = cpy.ideas[i];
    }
    std::cout << "Brain Copy Assignement Constructor Called" << std::endl;
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain Destructor Called" << std::endl;
}