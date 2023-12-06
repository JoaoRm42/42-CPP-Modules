//
// Created by Juanito on 04/12/2023.
//

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    this->_name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &cpy) : ClapTrap(cpy), FragTrap(cpy), ScavTrap(cpy) {
    *this = cpy;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap) {
    ClapTrap::_name = diamondtrap._name + "_clap_name";
    this->_name = diamondtrap._name;
    this->attackDamage = diamondtrap.attackDamage;
    this->energyPoints = diamondtrap.energyPoints;
    this->hitPoints = diamondtrap.hitPoints;
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(std::string target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name is: " << this->_name << std::endl;
    std::cout << "Claptrap name is: " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::GetDiamondTrapName() const {
    return (this->_name);
}

std::ostream &operator<<(std::ostream &out, DiamondTrap const &diamondTrap)
{
    out << std::endl;
    out << "Name: " << diamondTrap.GetDiamondTrapName() << std::endl;
    out << "Attack Damage: " << diamondTrap.getAttackDamage() << std::endl;
    out << "Energy left: " << diamondTrap.getEnergyPoints() << std::endl;
    out << "Life left: " << diamondTrap.getHitPoints() << std::endl;
    return out;
}