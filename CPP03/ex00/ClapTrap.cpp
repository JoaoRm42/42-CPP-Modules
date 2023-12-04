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
    std::cout << "ClapTrap " << this->Name;
    std::cout << " has received " << amount;
    std::cout << " points of damage!" << std::endl;
}

void ClapTrap::beRapaired(unsigned int amount) {
    std::cout << "ClapTrap " << this->Name;
    std::cout << " has been repaired " << amount;
    std::cout << " health points" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &teste) {
    out << std::endl;
    out << "Name: " << teste.getName() << std::endl;
    out << "Attack Damage: " << teste.getDamage() << std::endl;
    out << "Energy left: " << teste.getEnergy() << std::endl;
    out << "Life left: " << teste.getLife() << std::endl;
    return out;
}