#include "Zombie.h"

std::string Zombie::getName() {
    return(this->name);
}

Zombie::Zombie(std::string name) {
}

Zombie::~Zombie() {
    std::cout << "Zombie: " << getName() << " has been destroyed!" << std::endl;
}