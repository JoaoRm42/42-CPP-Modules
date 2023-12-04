//
// Created by joaoped2 on 11/29/23.
//

#include "ClapTrap.hpp"

int main() {
    ClapTrap robot1("player1");

    robot1.attack("player2");
    std::cout << robot1 << std::endl;
    robot1.takeDamage(2);
    std::cout << robot1 << std::endl;
    return (0);
}