//
// Created by Juanito on 04/12/2023.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    this->_name = "joaoped2";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name) : ClapTrap() {
    this->_name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &frag) : ClapTrap(frag) {
    std::cout << "FragTrap Copy Constructor Called" << std::endl;
    *this = frag;
}

FragTrap &FragTrap::operator=(const FragTrap &frag) {
    this->_name = frag._name;
    this->hitPoints = frag.hitPoints;
    this->energyPoints = frag.energyPoints;
    this->attackDamage = frag.attackDamage;
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->energyPoints != 0 && this->hitPoints != 0) {
        std::cout << "FragTrap " << this->_name;
        std::cout << " attacks " << target;
        std::cout << " causing " << this->attackDamage;
        std::cout << " points of damage!" << std::endl;
        this->energyPoints -= 1;
    }
    else {
        std::cout << "Cannot attack because " << this->_name;
        std::cout << " is really weak!" << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    std::cout << "Give high five to your bro!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const FragTrap &frag) {
    out << std::endl;
    out << "Name:          " << frag.getName() << std::endl;
    out << "Attack Damage: " << frag.getAttackDamage() << std::endl;
    out << "Energy left:   " << frag.getEnergyPoints() << std::endl;
    out << "Life left:     " << frag.getHitPoints() << std::endl;
    return out;
}