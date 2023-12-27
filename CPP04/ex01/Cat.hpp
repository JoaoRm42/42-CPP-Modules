//
// Created by Juanito on 18/12/2023.
//

#ifndef CPP_MODULES_42_CAT_HPP
#define CPP_MODULES_42_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
    private:
        Brain* CatBrain;
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat& cpy);
        Cat& operator = (const Cat& cat);
        ~Cat();
        void makeSound() const;
        Brain *getBrain() const;
};


#endif //CPP_MODULES_42_CAT_HPP
