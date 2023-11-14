#ifndef CPP_MODULES_42_ZOMBIE_H
#define CPP_MODULES_42_ZOMBIE_H
#include <iostream>
#include <cstdlib>

class Zombie {
    private:
        std::string name;

    public:
        void announce ( void );
        std::string getName();
        void setName( std::string name );
        Zombie();
        Zombie(std::string name);
        ~Zombie();
};

//------------zombieHorde------------||
Zombie *zombieHorde(int N, std::string name);

#endif //CPP_MODULES_42_ZOMBIE_H
