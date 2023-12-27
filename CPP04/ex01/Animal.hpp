//
// Created by Juanito on 18/12/2023.
//

#ifndef CPP_MODULES_42_ANIMAL_HPP
#define CPP_MODULES_42_ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& cpy);
        Animal& operator = (const Animal& animal);
        virtual ~Animal();
        void setType(std::string type);
        std::string getType() const;
        virtual void makeSound() const;
};

#endif //CPP_MODULES_42_ANIMAL_HPP
