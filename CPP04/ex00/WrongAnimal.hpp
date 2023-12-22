//
// Created by Juanito on 18/12/2023.
//

#ifndef CPP_MODULES_42_WRONGANIMAL_HPP
#define CPP_MODULES_42_WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std.:string type);
        WrongAnimal(const WrongAnimal& cpy);
        WrongAnimal& operator = (const WrongAnimal& animal);
        ~WrongAnimal();
        const std::string getType();
        void setType(std::string);
        const void makeSound(void);
};


#endif //CPP_MODULES_42_WRONGANIMAL_HPP
