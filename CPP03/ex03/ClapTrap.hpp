//
// Created by joaoped2 on 11/29/23.
//

#ifndef CPP_MODULES_42_CLAPTRAP_HPP
#define CPP_MODULES_42_CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    protected:
        std::string _name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        ClapTrap();
        ClapTrap( std::string name);
        ClapTrap( const ClapTrap& cpy );
        ClapTrap& operator = ( const ClapTrap& claptrap );
        ~ClapTrap();
        void attack( const std::string& target );
        void takeDamage( unsigned  int amount);
        void beRapaired( unsigned int amount);

        //Getters
        std::string getName( void ) const;
        int getHitPoints( void ) const;
        int getEnergyPoints( void ) const;
        int getAttackDamage( void ) const;
};

std::ostream &operator<<(std::ostream &out, const ClapTrap &teste);

#endif //CPP_MODULES_42_CLAPTRAP_HPP
