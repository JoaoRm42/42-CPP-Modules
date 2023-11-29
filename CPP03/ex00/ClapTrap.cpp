//
// Created by joaoped2 on 11/29/23.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) {
    this->Name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy) {
    std::cout << "Copy Constructor Called" << std::endl;
    *this = cpy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
    this->Name = claptrap.Name;
    this->hitPoints = claptrap.hitPoints;
    this->energyPoints = claptrap.energyPoints;
    this->attackDamage = claptrap.attackDamage;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string &target) {
    std::cout << "ClapTrap " << this->Name;
    std::cout << " attacks " << target;
    std::cout << " causing " << this->attackDamage;
    std::cout << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRapaired(unsigned int amount) {

}