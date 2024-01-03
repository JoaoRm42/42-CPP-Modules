//
// Created by joaoped2 on 1/3/24.
//

#ifndef CPP_MODULES_42_CHARACTER_HPP
#define CPP_MODULES_42_CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

class Character: public ICharacter {
    private:
        std::string name;
        AMateria* inventory[4];
        AMateria* drop[4];
        int index;
    public:
        Character();
        Character(std::string name);
        Character(Character const& cpy);
        Character& operator=(Character const& cpy);
        ~Character();
        void equip(AMateria* spell);
        void unequip(int index);
        void use(int index, ICharacter& target);
        std::string const& getName()const;
};


#endif //CPP_MODULES_42_CHARACTER_HPP
