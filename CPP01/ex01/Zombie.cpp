#include "Zombie.h"

std::string Zombie::getName() {
    return(this->name);
}

void Zombie::setName( std::string name ) {
    this->name = name;
}

Zombie::Zombie() {
    return ;
}

Zombie::Zombie( std::string name ) {
}

Zombie::~Zombie() {
    std::cout << "Zombie: " << getName() << " has been destroyed!" << std::endl;
}

void Zombie::announce( void ) {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}