#include "Zombie.h"

void Zombie::randomChump( std::string name ) {
    Zombie* tmp = new Zombie(name);
    tmp->announce();
    delete (tmp);
    return ;
}