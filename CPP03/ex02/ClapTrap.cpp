//
// Created by joaoped2 on 11/29/23.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) {
    this->Name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy) {
    std::cout << "ClapTrap Copy Constructor Called" << std::endl;
    *this = cpy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
    this->Name = claptrap.Name;
    this->hitPoints = claptrap.hitPoints;
    this->energyPoints = claptrap.energyPoints;
    this->attackDamage = claptrap.attackDamage;
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string &target) {

    if (this->energyPoints != 0 && this->hitPoints != 0) {
        std::cout << "ClapTrap " << this->Name;
        std::cout << " attacks " << target;
        std::cout << " causing " << this->attackDamage;
        std::cout << " points of damage!" << std::endl;
        this->energyPoints -= 1;
    }
    else {
        std::cout << "Cannot attack because " << this->Name;
        std::cout << " is really weak!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->energyPoints != 0 && this->hitPoints != 0) {
        std::cout << "ClapTrap " << this->Name;
        std::cout << " has received " << amount;
        std::cout << " points of damage!" << std::endl;

        this->hitPoints -= amount;
    }
    else {
        std::cout << "Cannot attack because " << this->Name;
        std::cout << " is really weak!" << std::endl;
    }
    if (this->hitPoints < 0)
        this->hitPoints = 0;
}

void ClapTrap::beRapaired(unsigned int amount) {
    if (this->energyPoints != 0 && this->hitPoints != 0) {
        std::cout << "ClapTrap " << this->Name;
        std::cout << " has been repaired " << amount;
        std::cout << " health points" << std::endl;
        this->hitPoints += amount;
        this->energyPoints -= 1;
    }
    else {
        std::cout << "Cannot attack because " << this->Name;
        std::cout << " is really weak!" << std::endl;
    }
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called" << std::endl;
}

std::string ClapTrap::getName() const {
    return (this->Name);
}

int ClapTrap::getHitPoints() const {
    return (this->hitPoints);
}

int ClapTrap::getEnergyPoints() const {
    return (this->energyPoints);
}

int ClapTrap::getAttackDamage() const {
    return (this->attackDamage);
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &teste) {
    out << std::endl;
    out << "Name:          " << teste.getName() << std::endl;
    out << "Attack Damage: " << teste.getAttackDamage() << std::endl;
    out << "Energy left:   " << teste.getEnergyPoints() << std::endl;
    out << "Life left:     " << teste.getHitPoints() << std::endl;
    return out;
}