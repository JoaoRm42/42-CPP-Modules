//
// Created by Juanito on 18/12/2023.
//

#ifndef CPP_MODULES_42_DOG_HPP
#define CPP_MODULES_42_DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog& cpy);
        Dog& operator = (const Dog& dog);
        ~Dog();
        void makeSound() const;
};


#endif //CPP_MODULES_42_DOG_HPP
