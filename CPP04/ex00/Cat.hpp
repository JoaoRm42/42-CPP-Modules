//
// Created by Juanito on 18/12/2023.
//

#ifndef CPP_MODULES_42_CAT_HPP
#define CPP_MODULES_42_CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat& cpy);
        Cat& operator = (const Cat& cat);
        ~Cat();
        void makeSound() const;
};


#endif //CPP_MODULES_42_CAT_HPP
