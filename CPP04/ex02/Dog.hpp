//
// Created by Juanito on 18/12/2023.
//

#ifndef CPP_MODULES_42_DOG_HPP
#define CPP_MODULES_42_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
    private:
        Brain* DogBrain;
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog& cpy);
        Dog& operator = (const Dog& dog);
        ~Dog();
        void makeSound() const;
        Brain *getBrain() const;
};


#endif //CPP_MODULES_42_DOG_HPP
