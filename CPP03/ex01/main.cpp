//
// Created by joaoped2 on 11/29/23.
//

#include "ScavTrap.hpp"

int main() {
    ScavTrap teste("Bad-Boy");
    teste.attack("Alguem");
    std::cout << "O nome do ScavTrap e: " << teste.getName() << std::endl;
    std::cout << teste << std::endl;
    teste.attack("Good-boy");
    std::cout << teste.getAttackDamage() << std::endl;
    teste.attack("Good-boy");
    std::cout << teste << std::endl;
    teste.guardGate();

//    ClapTrap robot1("player1");
//
//    robot1.attack("player2");
//    std::cout << robot1 << std::endl;
//    robot1.takeDamage(2);
//    std::cout << robot1 << std::endl;
//    robot1.beRapaired(10);
//    std::cout<< robot1 << std::endl;
//    robot1.takeDamage(20);
//    std::cout << robot1 << std::endl;
//    robot1.attack("player3");
//    std::cout << robot1 << std::endl;
//    robot1.beRapaired(100);
//    std::cout << robot1 << std::endl;
//    robot1.takeDamage(30);
//    std::cout << robot1 << std::endl;
    return (0);
}