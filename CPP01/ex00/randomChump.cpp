#include "Zombie.h"

void Zombie::randomChump( std::string name ) {
    Zombie Zombie(name);
    Zombie.announce();
    return ;
}