//
// Created by joaoped2 on 11/14/23.
//


#include "Weapon.hpp"

const std::string &Weapon::getType() {
    return (this->type);
}

void Weapon::setType( std::string newtype ) {
    this->type = newtype;
    return ;
}

Weapon::Weapon(std::string name) {
    this->type = name;
}

Weapon::Weapon() {

}

Weapon::~Weapon() {

}