//
// Created by joaoped2 on 11/14/23.
//

#ifndef CPP_MODULES_42_HUMANA_HPP
#define CPP_MODULES_42_HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& arma;

    public:
        HumanA( std::string name, Weapon& weapongiven );
        ~HumanA();
        void attack();
};

#endif //CPP_MODULES_42_HUMANA_HPP
