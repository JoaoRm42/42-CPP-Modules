//
// Created by joaoped2 on 11/14/23.
//

#ifndef CPP_MODULES_42_HUMANB_HPP
#define CPP_MODULES_42_HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon *arma;

public:
    HumanB( std::string name );
    ~HumanB();
    void attack();
    void setWeapon( Weapon &neweapon );
};

#endif //CPP_MODULES_42_HUMANB_HPP
