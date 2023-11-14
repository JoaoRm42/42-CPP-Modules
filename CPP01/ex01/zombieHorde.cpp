#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name) {
    Zombie *cpy = new Zombie[N];

    for (int index = 0; index < N; index++)
        cpy[index].setName(name);
    return cpy;
}