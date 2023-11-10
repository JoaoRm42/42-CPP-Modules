//
// Created by joaoped2 on 11/10/23.
//

#include "Zombie.h"

void Zombie::announce( void ) {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() {
    return(this->name);
}

Zombie::Zombie() {
    this->name = "joaoped2";
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << "Zombie: " << getName() << " has been destroyed!" << std::endl;
}