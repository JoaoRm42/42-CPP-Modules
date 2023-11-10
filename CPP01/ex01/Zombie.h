#ifndef CPP_MODULES_42_ZOMBIE_H
#define CPP_MODULES_42_ZOMBIE_H
#include <iostream>

class Zombie {
    private:
        std::string name;

    public:
        Zombie* zombieHorde( int N, std::string name );
        void announce ( void );
        std::string getName();
        Zombie(std::string name);
        ~Zombie();
};

#endif //CPP_MODULES_42_ZOMBIE_H
