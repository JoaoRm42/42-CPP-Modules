//
// Created by Juanito on 18/12/2023.
//

#ifndef CPP_MODULES_42_WRONGCAT_HPP
#define CPP_MODULES_42_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat& cpy);
        WrongCat& operator = (const WrongCat& cpy);
        ~WrongCat();
        void makeSound() const;
};


#endif //CPP_MODULES_42_WRONGCAT_HPP
