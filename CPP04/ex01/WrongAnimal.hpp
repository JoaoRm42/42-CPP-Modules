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
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& cpy);
        WrongAnimal& operator = (const WrongAnimal& animal);
        virtual ~WrongAnimal();
        std::string getType() const;
        void setType(std::string type);
        virtual void makeSound() const;
};


#endif //CPP_MODULES_42_WRONGANIMAL_HPP
