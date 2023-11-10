//
// Created by joaoped2 on 11/10/23.
//

#ifndef CPP_MODULES_42_ZOMBIE_H
#define CPP_MODULES_42_ZOMBIE_H
#include <iostream>

class Zombie {
    private:
        std::string name;

    public:
        Zombie* newZombie( std::string name );
        void randomChump( std::string name );
        void announce ( void );
        std::string getName();
        Zombie();
        Zombie(std::string name);
        ~Zombie();
};

#endif //CPP_MODULES_42_ZOMBIE_H
