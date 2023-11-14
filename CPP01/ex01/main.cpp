#include "Zombie.h"

int main()
{
    Zombie *zb;
    std::string name;
    int count;

    system("clear");
    std::cout << "Number of Zombies?" << std::endl;
    std::cin >> count;
    if (count <= 0) {
        std::cout << "Invalid Number" << std::endl;
        return (0);
    }
    std::cout << "Give them a name" << std::endl;
    std::cin >> name;
    if (name.empty()) {
        std::cout << "name must have atleast one character" << std::endl;
        return (0);
    }
    system("clear");
    zb = zombieHorde(count, name);
    for (int index = 0; index < count; index++) {
        std::cout << index + 1 << std::endl;
        zb[index].announce();
        std::cout << "------------------------------------" << std::endl;
    }
    delete[] zb;
    return (0);
}