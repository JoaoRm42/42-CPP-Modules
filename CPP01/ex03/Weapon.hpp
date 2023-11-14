//
// Created by joaoped2 on 11/14/23.
//

#ifndef CPP_MODULES_42_WEAPON_HPP
#define CPP_MODULES_42_WEAPON_HPP

#include <iostream>

class Weapon {
    private:
        std::string type;

    public:
        Weapon();
        Weapon(std::string name);
        ~Weapon();
        const std::string& getType();
        void setType( std::string newtype );
};

#endif //CPP_MODULES_42_WEAPON_HPP
