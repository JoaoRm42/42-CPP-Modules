//
// Created by joaoped2 on 11/14/23.
//

#include "HumanB.hpp"

void HumanB::attack() {
    if (this->arma->getType().empty()) {
        std::cout << this->name << " doesn't have a Weapon" << std::endl;
        return ;
    }
    std::cout << this->name << " attacks with their " << this->arma->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &neweapon) {
    arma = &neweapon;
    return ;
}

HumanB::HumanB( std::string name ) : name(name) {
    return ;
}

HumanB::~HumanB() {
    return ;
}