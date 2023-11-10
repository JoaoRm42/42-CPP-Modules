#include "Zombie.h"

int main()
{
    Zombie zb;
    Zombie* newzombie = zb.newZombie("Foo");
    Zombie* newzombie2 = zb.newZombie("Foo2");
    zb.randomChump("Foo3");

    std::cout << zb.getName() << std::endl;
    std::cout << newzombie->getName() << std::endl;
    std::cout << newzombie2->getName() << std::endl;

    delete (newzombie);
    delete (newzombie2);
    return (0);
}