//
// Created by Juanito on 04/12/2023.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav) {
    std::cout << "ScavTrap Copy Constructor Called" << std::endl;
    *this = scav;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scav) {
    this->Name = scav.Name;
    this->hitPoints = scav.hitPoints;
    this->energyPoints = scav.energyPoints;
    this->attackDamage = scav.attackDamage;
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->energyPoints != 0 && this->hitPoints != 0) {
        std::cout << "ScavTrap " << this->Name;
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

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now on Gate Keep Mode!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ScavTrap &scav) {
    out << std::endl;
    out << "Name:          " << scav.getName() << std::endl;
    out << "Attack Damage: " << scav.getAttackDamage() << std::endl;
    out << "Energy left:   " << scav.getEnergyPoints() << std::endl;
    out << "Life left:     " << scav.getHitPoints() << std::endl;
    return out;
}